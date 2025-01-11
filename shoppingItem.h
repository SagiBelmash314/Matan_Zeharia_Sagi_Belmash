#pragma once
#include "product.h"

typedef struct {
	char barcode[BARCODE_LEN];
	float price;
	int amountInCart;
} ShoppingItem;

float calculatePrice(const ShoppingItem* item);
void initItem(Product* p, ShoppingItem* item);
void printItem(Product* p);
void freeItem(ShoppingItem* item);
Product matchingProduct(ShoppingItem* item);
