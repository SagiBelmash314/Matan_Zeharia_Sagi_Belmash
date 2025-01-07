#pragma once
#include "date.h"

#define MAX_NAME_LEN 20
#define BARCODE_LEN 7


typedef enum { SH, FZ, FR, FV, NofTypes } Type;
const char* typeTilte[NofTypes];

typedef struct
{
	char name[MAX_NAME_LEN + 1];
	char barcode[BARCODE_LEN];
	Type type;
	float price;
	int amount;
	Date* expDate;
} Product;

void initProduct(Product* p);

void printProduct(const Product* p);