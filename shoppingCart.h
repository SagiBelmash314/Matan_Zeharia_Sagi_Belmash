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

