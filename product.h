#pragma once
#include "date.h"

#define MAX_NAME_LEN 20
#define BARCODE_LEN 7


typedef enum { SH, FZ, FR, FV, NofTypes } Type;
const char* typeTilte[NofTypes];
const char* typeAbr[NofTypes];

typedef struct
{
	char name[MAX_NAME_LEN + 1];
	char barcode[BARCODE_LEN];
	Type type;
	float price;
	int amount;
	Date expDate;
} Product;

int initProduct(const Product** productList, const int prodAmount, Product* pP);
void printProduct(const Product* pP);
Type getTypeFromUser();
int compareProductByBarcode(const void* a, const void* b);
int compareProductByName(const void* a, const void* b);
Product* getProductByBarcode(const Product** productList, const int prodAmount, const char* barcode);
Product* getProductByName(const Product** productList, const int prodAmount, const char* name);