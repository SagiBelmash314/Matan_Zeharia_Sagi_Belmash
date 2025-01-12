#pragma once
#include "product.h"

typedef struct {
	char barcode[BARCODE_LEN];
	float price;
	int amountInCart;
} ShoppingItem;

float calculatePrice(const ShoppingItem* pSI);
void initItem(const Product* pP, const int amount, ShoppingItem* pSI);
void printItem(const ShoppingItem* pSI);
void freeItem(ShoppingItem* item);
int compareItemByBarcode(const void* a, const void* b);
ShoppingItem* getItemByBarcode(const ShoppingItem** itemList, const int itemAmount, const char* barcode);