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
	pSM->customers = NULL;
	pSM->products = NULL;
	return getSMNameFromUser(pSM) ? 1 : 0;
}

void printSuperMarket(const SuperMarket* pSM)
{
	printf("\nSuper Market's name: %s\nNumber of products: %d\nNumber of customers: %d\n----------\n", pSM->name, pSM->prodAmount, pSM->custAmount);
	puts("Product list:");
	for (int i = 0; i < pSM->prodAmount; i++)
	{
		printProduct(pSM->products[i]);
		printf("\n");
	}
	puts("Customers List:");
	for (int i = 0; i < pSM->custAmount; i++)
	{
		//printCustomer(pSM->customers[i]);
		printf("\n");
	}
}

int getProductIndex(const SuperMarket* pSM, const Product* pP)
{
	for (int i = 0; i < pSM->prodAmount; i++)
		if (!strcmp(pSM->products[i]->name, pP->name))
			return i;
	return -1;
}

void increaseProductAmount(SuperMarket* pSM, const Product* pP)
{
	int i = 0;
	while (strcmp(pSM->products[i]->name, pP->name)) i++;
	pSM->products[i]->amount += pP->amount;
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
		pSM->products = (Product**)safeRealloc(pSM->products, sizeof(Product*) * ++pSM->prodAmount);
		if (!pSM->products)
			return 0;
		pSM->products[pSM->prodAmount - 1] = pP;
	}
	return 1;
}

int addCustomer(SuperMarket* pSM)
{
	Customer c;
	if (!initCustomer(&c))
		return 0;
	if (findCustomerById(pSM->customers, c.id) == -1)
	{
		puts("Customer already exists");
		return 1;
	}
	pSM->customers = (Customer*)safeRealloc(pSM->customers, sizeof(Customer) * ++pSM->custAmount);
	if (!pSM->customers)
		return 0;
	pSM->customers[pSM->custAmount - 1] = c;
	return 1;
}



int buy(SuperMarket* pSM)
{

}

int ableToPurchase(const Customer* c)
{

}

int purchase(SuperMarket* pSM)
{
	int input = getStrFromUser("Enter customer's id or name:");
	if (!input)
		return 0;
	int index = max(findCustomerById(pSM->customers, pSM->custAmount, input), findCustomerByName(pSM->customers, pSM->custAmount, input));
	if (index == -1)
	{
		puts("Customer doesn't exist");
		return 1;
	}
	Customer c = pSM->customers[index];
	if (!c.cart->totalAmount)
	{
		puts("Customer's cart is empty");
		return 1;
	}

	printf("Total price is: %.2f", calculateTotal(c.cart));
	return 1;
}

int cancel(SuperMarket* pSM)
{

}

int manageCart

void printProductsByType(const SuperMarket* pSM)
{
	Type t = getTypeFromUser();
	for (int i = 0; i < pSM->prodAmount; i++)
		if (pSM->products[i]->type == t)
		{
			printProduct(pSM->products[i]);
			printf("\n");
		}
}

void freeSuperMarket(SuperMarket* pSM)
{
	/*
	for (int i = 0; i < pSM->custAmount; i++)
	{
		freeCustomer(pSM->customers + i);
		free(pSM->customers + i);
	}
	*/
	for (int i = 0; i < pSM->prodAmount; i++)
		free(pSM->products[i]);
	free(pSM->products);
	free(pSM->customers);
	free(pSM->name);
}
