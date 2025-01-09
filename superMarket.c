#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "superMarket.h"
#include "general.h"

int getSMNameFromUser(SuperMarket* pSM)
{
	pSM->name = getStrFromUser("Please enter the supermarket's name:");
	return pSM->name ? 1 : 0;
}

int initSuperMarket(SuperMarket* pSM)
{
	pSM->custAmount = 0;
	pSM->prodAmount = 0;
	pSM->customerList = NULL;
	pSM->productList = NULL;
	return getSMNameFromUser(pSM) ? 1 : 0;
}

void printSuperMarket(const SuperMarket* pSM)
{
	printf("\nSuper Market's name: %s\nNumber of productList: %d\nNumber of customerList: %d\n----------\n", pSM->name, pSM->prodAmount, pSM->custAmount);
	puts("Product list:");
	for (int i = 0; i < pSM->prodAmount; i++)
	{
		printProduct(pSM->productList[i]);
		printf("\n");
	}
	puts("Customers List:");
	for (int i = 0; i < pSM->custAmount; i++)
	{
		//printCustomer(pSM->customerList[i]);
		printf("\n");
	}
}

int getProductIndex(const SuperMarket* pSM, const Product* pP)
{
	for (int i = 0; i < pSM->prodAmount; i++)
		if (!strcmp(pSM->productList[i]->name, pP->name))
			return i;
	return -1;
}

void increaseProductAmount(SuperMarket* pSM, const Product* pP)
{
	int i = 0;
	while (strcmp(pSM->productList[i]->name, pP->name)) i++;
	pSM->productList[i]->amount += pP->amount;
}

int addProduct(SuperMarket* pSM)
{
	Product* pP = (Product*)malloc(sizeof(Product));
	if (!pP)
		return 0;
	initProduct(pP);
	int index = getProductIndex(pSM, pP);
	if (index != -1)
		increaseProductAmount(pSM, pP);
	else
	{
		pSM->productList = (Product**)safeRealloc(pSM->productList, sizeof(Product*) * ++pSM->prodAmount);
		if (!pSM->productList)
			return 0;
		pSM->productList[pSM->prodAmount - 1] = pP;
	}
	return 1;
}

int addCustomer(SuperMarket* pSM)
{
	Customer c;
	if (!initCustomer(&c))
		return 0;
	if (findCustomerById(pSM->customerList, c.id) == -1)
	{
		puts("Customer already exists");
		return 1;
	}
	pSM->customerList = (Customer*)safeRealloc(pSM->customerList, sizeof(Customer) * ++pSM->custAmount);
	if (!pSM->customerList)
		return 0;
	pSM->customerList[pSM->custAmount - 1] = c;
	return 1;
}



int buy(SuperMarket* pSM)
{

}

Customer* getCustomerForPayment(const Customer* customerList, const int custAmount, const char* input)
{
	int index = max(findCustomerById(customerList, custAmount, input), findCustomerByName(customerList,custAmount, input));
	if (index == -1)
	{
		puts("Customer doesn't exist");
		return NULL;
	}
	if (customerList[index].cart->totalAmount)
	{
		puts("Customer's cart is empty");
		return NULL;
	}
	return customerList + index;
}

int payment(SuperMarket* pSM)
{
	
}

int cancelPurchase(SuperMarket* pSM)
{

}

int manageCart(SuperMarket* pSM)
{
	char* input = getStrFromUser("Enter customer's id or name:");
	if (!input)
		return 0;
	Customer* pC = getCustomerForPayment(pSM->customerList, pSM->custAmount, input);
	if (!pC)
		return 1;
	// printCart(pC->c);
	printf("Total price is: %.2f", calculateTotal(pC->cart));
	int action;
	do
	{

	} while (action != 1 && action != 2);
	return 1;
}

void printProductsByType(const SuperMarket* pSM)
{
	Type t = getTypeFromUser();
	for (int i = 0; i < pSM->prodAmount; i++)
		if (pSM->productList[i]->type == t)
		{
			printProduct(pSM->productList[i]);
			printf("\n");
		}
}

void freeSuperMarket(SuperMarket* pSM)
{
	/*
	for (int i = 0; i < pSM->custAmount; i++)
	{
		freeCustomer(pSM->customerList + i);
		free(pSM->customerList + i);
	}
	*/
	for (int i = 0; i < pSM->prodAmount; i++)
		free(pSM->productList[i]);
	free(pSM->productList);
	free(pSM->customerList);
	free(pSM->name);
}
