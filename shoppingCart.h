#pragma once
#include "shoppingItem.h"

typedef struct {
	ShoppingItem** itemList;
	float price;
	int amount;
}ShoppingCart;
void initCart(const ShoppingCart* cart);
int addItem(ShoppingItem** item, ShoppingCart* cart);
float calculateTotal(const ShoppingCart* cart);
void printCart(const ShoppingCart* s);
void freeCart(ShoppingCart* pCart);


