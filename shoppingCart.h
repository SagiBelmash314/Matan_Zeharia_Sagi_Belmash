#pragma once
#include "product.h"

#include "ShoppingItem.h"

typedef struct {
	char* barcode[BARCODE_LEN];
	float price;
	int amount;
	ShoppingItem** itemList;
} ShoppingCart;

int calculatePrice(const ShoppingItem* item);
void initItem(Product* p, ShoppingItem* item);
void addItem(ShoppingItem** item, ShoppingCart* cart);
void printCart(ShoppingCart* s);