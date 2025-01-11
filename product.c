#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "general.h"
#include "product.h"


const char* typeTilte[NofTypes] = { "Shelf", "Frozen", "Fridge", "FruitVegtable" };
const char* typeAbr[NofTypes] = { "SH", "FZ", "FR", "FV" };

Type getTypeFromUser()
{
	int t;
	do {
		puts("\nPlease enter one of the following types:");
		for (int i = 0; i < NofTypes; i++)
			printf("%d for %s\n", i, typeTilte[i]);
		scanf("%d", &t);
		getchar();
	} while (t < 0 || t >= NofTypes);
	return (Type)t;
}

int compareProductByBarcode(const void* a, const void* b)
{
	return (strcmp((*(Product**)a)->barcode, (*(Product**)b)->barcode));
}

float getPriceFromUser()
{
	float price;
	while (1)
	{
		puts("\nPlease enter product's price:");
		scanf("%f", &price);
		getchar();
		if (price <= 0)
			puts("\nThe price should be above 0");
		else break;
	}
	return price;
}

int getAmountFromUser()
{
	int amount;
	while (1)
	{
		puts("\nPlease enter product's amount:");
		scanf("%d", &amount);
		getchar();
		if (amount <= 0)
			puts("The amount should be above 0\n");
		else break;
	}
	return amount;
}



int initProduct(Product* pP)
{
	strcpy(pP->name, getStrFromUser("\nPlease enter the product's name:"));
	pP->type = getTypeFromUser();
	do
	{
		createBarcode(pP);
	}
	while (getProductByBarcode(productList, prodAmount, pP->barcode));
	pP->price = getPriceFromUser();
	pP->amount = getAmountFromUser();
	Date d;
	initDate(&d);
	pP->expDate = d;
	return 1;
}


void printProduct(const Product* pP)
{
	printf("\nProduct name: %s\nBarcode: %s\nType: %s\nPrice: %.2f\nAmount in stock: %d\nExpiration date: ", pP->name, pP->barcode, typeTilte[pP->type], pP->price, pP->amount);
	printDate(pP->expDate);
}