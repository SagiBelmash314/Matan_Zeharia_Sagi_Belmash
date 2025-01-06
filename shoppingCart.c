#include "shoppingCart.h"

void initCart(shoppingCart* cart) {
	cart->itemList = malloc(sizeof(cart));
	cart->amount = 0;
}

void addItem(shoppingItem** item, shoppingCart* cart) {
	cart->amount += 1;
	cart->itemList = (shoppingItem*)realloc(cart->amount * (sizeof(shoppingItem*)));
	cart->itemList[cart->amount - 1] = item;
}

int calculateTotal(shoppingCart* cart) {
	int total = 0;
	for (int i = 0; i < cart->amount; i++)
		total += calculatePrice(cart->itemList[i]);
	return total;
}