#include <stdlib.h>
#include <stdio.h>
#include "ShoppingCart.h"
#include "general.h"
#include "general.h"

void initCart(ShoppingCart* cart) {
	cart->itemList = malloc(sizeof(ShoppingItem*));
	cart->amount = 0;
}

int addItem(ShoppingItem** item, ShoppingCart* cart) {
	cart->totalAmount += 1;
	cart->itemList = (ShoppingItem**)malloc(cart->totalAmount * (sizeof(ShoppingItem*)));
	if (!cart->itemList)
		return 0;
	cart->itemList[cart->totalAmount - 1] = *item;
	return 1;
}

float calculateTotal(const ShoppingCart* cart) {
	float total = 0;
	for (int i = 0; i < cart->totalAmount; i++)
		total += calculatePrice(cart->itemList[i]);
	return total;
}

void printCart(ShoppingCart* s) {
	printf("this cart has %d items:",s->amount);
	for (int i = 0; i < s->amount; i++)
		printItem(s->itemList[i]);
	printf("the total sum is:%f", s->price);
}