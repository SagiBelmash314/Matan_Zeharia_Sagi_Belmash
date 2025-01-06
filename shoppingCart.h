#pragma once
#include "shoppingItem.h"

typedef struct {
	char* barcode[BARCODE_LEN];
	float price;
	int amount;
	shoppingItem** itemList;
} shoppingCart;

int calculatePrice(const shoppingItem* item);
void initItem(Product* p, shoppingItem* item);