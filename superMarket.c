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

//1
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

//2
int addProduct(SuperMarket* pSM)
{
	Product* pP = (Product*)malloc(sizeof(Product));
	if (!pP)
		return 0;
	initProduct(pSM->productList, pSM->prodAmount, pP);
	Product* pExistingProduct = bsearch(pP, pSM->productList, pSM->prodAmount, sizeof(Product*), compareProductByName);
	if (pExistingProduct)
		pExistingProduct->amount += pP->amount;
	else
	{
		pSM->productList = (Product**)safeRealloc(pSM->productList, sizeof(Product*) * ++pSM->prodAmount);
		if (!pSM->productList)
			return 0;
		pSM->productList[pSM->prodAmount - 1] = pP;
	}
	return 1;
}

//3
int addCustomer(SuperMarket* pSM)
{
	Customer c;
	if (!initCustomer(&c))
		return 0;
	if (getCustomerById(pSM->customerList, pSM->custAmount, c.id))
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

int getAmountFromUser(const SuperMarket* pSM, Product* pP, Customer* pC)
{
	int amount;
	printf("There are %d %ss in stock, how many do you want?\n", pP->amount, pP->name);
	scanf("%d", &amount);
	if (amount > pP->amount) printf("You can't have more than %d %ss\n", pP->amount, pP->name);
	else if (amount < 0) puts("You can't have buy less then 0");
	else
	{
		pP->amount -= amount;
		ShoppingItem item = getItemByBarcode(pSM->customerList, pSM->custAmount, pP->barcode);
		if (!item)
			addProducToCustomer(pC, pP);
		else
			item += amount;
		return 1;
	}
	return 0;
}

//4
int buy(SuperMarket* pSM)
{
	char* input = getStrFromUser("Enter customer's id:");
	if (!input)
		return 0;
	Customer* pC = getCustomerById(pSM->customerList, pSM->custAmount, input);
	if (!pC)
	{
		puts("Customer doesn't exist");
		return 1;
	}
	for (int i = 0; i < pSM->prodAmount; i++) printProduct(pSM->productList[i]);
	while (1)
	{
		free(input);
		input = getStrFromUser("\nEnter desired product's barcode (or 'stop' to stop buying):");
		if (!strcmp(input, "stop"))
		{
			free(input);
			return 1;
		}
		Product* pP = getProductByBarcode(pSM->customerList, pSM->prodAmount, input);
		if (!pP) puts("Product doesn't exist");
		else while (!getAmountFromUser(pSM, pP, pC));
	}
}

//5
int printCustomerCart(SuperMarket* pSM)
{
	char* input = getStrFromUser("\nEnter customer's id or name:");
	if (!input) return 0;
	Customer* pC = getCustomerById(pSM->customerList, pSM->custAmount, input);
	free(input);
	if (!pC)
	{
		puts("Customer doesn't exist");
		return 1;
	}
	if (!pC->cart->totalAmount)
	{
		puts("Customer's cart is empty");
		return 1;
	}
	printCart(pC->cart);
	return 1;
}

Customer* getCustomerForPayment(const Customer* customerList, const int custAmount, const char* input)
{
	Customer* pC = getCustomerById(customerList, custAmount, input);
	if (!pC)
	{
		pC = getCustomerByName(customerList, custAmount, input);
		if (!pC)
		{
			puts("Customer doesn't exist");
			return NULL;
		}
	}
	if (!pC->cart->totalAmount)
	{
		puts("Customer's cart is empty");
		return NULL;
	}
	return pC;
}


//6
int manageCart(SuperMarket* pSM)
{
	char* input = getStrFromUser("\nEnter customer's id or name:");
	if (!input) return NULL;
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

//7
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

//8
int quit(SuperMarket* pSM)
{
	for (int i = 0; i < pSM->custAmount; i++)
		if (pSM->customerList[i].cart->itemAmount > 0)
		{
			printf("\n%s's cart isn't empty, please complete or cancel the purchase before quitting\n", pSM->customerList[i].name);
			return 1;
		}
	freeSuperMarket(pSM);
	return 0;
}

