#pragma once

#include "ShoppingItem.h"

typedef struct {
	float price;
	int amount;
	ShoppingItem** itemList;
} ShoppingCart;

int calculatePrice(const ShoppingItem* item);
void initItem(Product* p, ShoppingItem* item);
void addItem(ShoppingItem** item, ShoppingCart* cart);
void printCart(ShoppingCart* s);