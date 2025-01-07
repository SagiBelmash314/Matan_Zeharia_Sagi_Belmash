#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "superMarket.h"
#include "general.h"


int getSMNameFromUser(SuperMarket* pSM)
{
	pSM->name = (char*)malloc(MAX_LEN);
	if (!pSM->name)
		return 0;
	do
	{
		puts("Please enter the super-market's name:");
		fgets(pSM->name, MAX_LEN, stdin);
		clearBuffer(pSM->name);
		for (int i = 0; i < strlen(pSM->name); i++)
			if (pSM->name[i] == '\n')
				pSM->name[i] = '\0';
	} while (!strlen(pSM->name));
	pSM->name = (char*)safeRealloc(pSM->name, (strlen(pSM->name) + 1) * sizeof(char));
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
	//Continue here
}

int addProduct(SuperMarket* pSM)
{
	pSM->products = (Product**)safeRealloc(pSM->products, sizeof(Product*) * ++pSM->prodAmount);
	if (!pSM->products)
		return 0;
	Product* pP = (Product*)malloc(sizeof(Product));
	if (!pP)
		return 0;
	initProduct(pP);
	pSM->products[pSM->prodAmount - 1] = pP;
	return 1;
}

int addCustomer(SuperMarket* pSM)
{
	pSM->customers = (Customer*)safeRealloc(pSM->customers, sizeof(Customer) * ++pSM->custAmount);
	if (!pSM->customers)
		return 0;
	Customer* pC = (Customer*)malloc(sizeof(Customer));
	if (!pC)
		return 0;
	//initCustomer(pC);
	pSM->customers[pSM->custAmount - 1] = *pC;
	free(pC);
	return 1;
}

int buy(SuperMarket* pSM)
{
	return 0;
}

void printProductsByType(const SuperMarket* pSM)
{
}

void freeSuperMarket(SuperMarket* pSM)
{
	/*
	for (int i = 0; i < pSM->custAmount; i++)
	{
		freeCustomer(pSM->customers + i);
	}
	*/
	for (int i = 0; i < pSM->prodAmount; i++)
	{
		freeProduct(pSM->products[i]);
		free(pSM->products[i]);
	}
	free(pSM->products);
	free(pSM->name);
}
