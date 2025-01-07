#pragma once
#include "shoppingItem.h"

typedef struct {
	ShoppingItem** itemList;
	int totalAmount;
} ShoppingCart;

float calculateTotal(const ShoppingCart* cart);
int addItem(ShoppingItem** item, ShoppingCart* cart);
void initCart(ShoppingCart* cart);
