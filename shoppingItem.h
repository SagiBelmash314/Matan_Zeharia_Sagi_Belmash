#pragma once
#include "product.h"

typedef struct {
	char* barcode[BARCODE_LEN];
	float price;
	int amount;
} shoppingItem;

int calculatePrice(const shoppingItem* item);
void initItem(Product* p, shoppingItem* item);
