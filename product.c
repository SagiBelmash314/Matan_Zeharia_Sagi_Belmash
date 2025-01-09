#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "general.h"
#include "date.h"
#include "product.h"


const char* typeTitle[NofTypes] = { "Shelf", "Frozen", "Fridge", "FruitVegtable" };
const char* typeAbr[NofTypes] = { "SH", "FZ", "FR", "FV" };

getNameFromUser(char* name)
{
	do
	{
		puts("Please enter the product's name:");
		fgets(name, MAX_NAME_LEN + 1, stdin);
		clearBuffer(name);
		for (int i = 0; i < MAX_NAME_LEN; i++)
			if (name[i] == '\n')
				name[i] = '\0';
	} while (!strlen(name));

}

Type getTypeFromUser()
{
	int t;
	do {
		puts("Please enter one of the following types:");
		for (int i = 0; i < NofTypes; i++)
			printf("%d for %s\n", i, typeTitle[i]);
		scanf("%d", &t);
		getchar();
	} while (t < 0 || t >= NofTypes);
	return (Type)t;
}


float getPriceFromUser()
{
	float price;
	while (true)
	{
		puts("Please enter product's price:");
		scanf("%f", &price);
		getchar();
		if (price <= 0)
			puts("The price should be above 0\n");
		else break;
	}
	return price;
}

int getAmountFromUser()
{
	int amount;
	while (true)
	{
		puts("Please enter amount of the product in stock:");
		scanf("%d", &amount);
		getchar();
		if (amount < 0)
			puts("The amount should be 0 or above");
		else break;
	}
	return amount;
}

void initProduct(Product* p)
{
	getNameFromUser(p->name);
	p->type = getTypeFromUser();
	p->barcode[0] = typeAbr[p->type][0];
	p->barcode[1] = typeAbr[p->type][1];
	for (int i = 2; i < BARCODE_LEN; i++)
	{
		srand(time(NULL));
		p->barcode[i] = rand() % 10 + '0';
	}
	p->price = getPriceFromUser();
	p->amount = getAmountFromUser();

	Date* d = (Date*)malloc(sizeof(d));
	initDate(d);
	p->expDate = d;
}

void printProduct(const Product* p)
{
	printf("\nProduct name: %s\nBarcode: %s\nType: %s\nPrice: %.2f\nAmount in stock: %d\nExpiration date: ", p->name, p->barcode, typeTitle[p->type], p->price, p->amount);
	printDate(p->expDate);
}

