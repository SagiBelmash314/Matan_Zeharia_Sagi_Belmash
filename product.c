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

int compareProductByName(const void* a, const void* b)
{
	return (strcmp((*(Product**)a)->name, (*(Product**)b)->name));
}

Product* getProductByBarcode(const Product** productList, const int prodAmount, const char* barcode)
{
	if (!(productList)) return NULL;
	Product p = { 0 };
	Product* pP = &p;
	strcpy(p.barcode, barcode);
	qsort(productList, prodAmount, sizeof(Product*), compareProductByBarcode);
	Product** pPP = (Product**)bsearch(&pP, productList, prodAmount, sizeof(Product*), compareProductByBarcode);
	return pPP ? *pPP : NULL;
}

Product* getProductByName(const Product** productList, const int prodAmount, const char* name)
{
	if (!(productList)) return NULL;
	Product p = { 0 };
	Product* pP = &p;
	strcpy(p.name, name);
	qsort(productList, prodAmount, sizeof(Product*), compareProductByName);
	Product** pPP = (Product**)bsearch(&pP, productList, prodAmount, sizeof(Product*), compareProductByName);
	return pPP ? *pPP : NULL;
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

void createBarcode(Product* pP)
{
	pP->barcode[0] = typeAbr[pP->type][0];
	pP->barcode[1] = typeAbr[pP->type][1];
	srand((unsigned)time(NULL));
	for (int i = 2; i < BARCODE_LEN; i++)
	{
		pP->barcode[i] = rand() % 10 + '0';
	}
	pP->barcode[BARCODE_LEN] = '\0';
}

int initProduct(const Product** productList, const int prodAmount, Product* pP)
{
	strcpy(pP->name, getStrFromUser("\nPlease enter the product's name:"));
	pP->type = getTypeFromUser();
	do
	{
		createBarcode(pP);
	} while (getProductByBarcode(productList, prodAmount, pP->barcode));
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