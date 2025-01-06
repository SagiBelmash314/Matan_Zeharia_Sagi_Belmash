#include "shoppingCart.h"

void initCart(ShoppingCart* cart) {
	cart->itemList = malloc(sizeof(cart));
	cart->totalAmount = 0;
}

void addItem(ShoppingItem** item, ShoppingCart* cart) {
	cart->totalAmount += 1;
	cart->itemList = (ShoppingItem*)realloc(cart->totalAmount * (sizeof(ShoppingItem*)));
	cart->itemList[cart->totalAmount - 1] = item;
}

int calculateTotal(ShoppingCart* cart) {
	int total = 0;
	for (int i = 0; i < cart->totalAmount; i++)
		total += calculatePrice(cart->itemList[i]);
	return total;
}