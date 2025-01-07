#pragma once
#include "product.h"

typedef struct {
	char* barcode[BARCODE_LEN];
	float price;
	int amount;
} ShoppingItem;

float calculatePrice(const ShoppingItem* item);
void initItem(Product* p, ShoppingItem* item);
