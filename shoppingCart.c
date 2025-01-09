#include <stdlib.h>
#include <stdio.h>
#include "ShoppingCart.h"
#include "general.h"

void initCart(ShoppingCart* cart) {
	cart->itemList = malloc(sizeof(ShoppingItem*));
	cart->amount = 0;
}

void addItem(ShoppingItem** item, ShoppingCart* cart) {
	cart->amount += 1;
	cart->itemList = (ShoppingItem*)safeRealloc(cart->itemList,cart->amount * (sizeof(ShoppingItem*)));
	cart->itemList[cart->amount - 1] = item;
}

int calculateTotal(ShoppingCart* cart) {
	int total = 0;
	for (int i = 0; i < cart->amount; i++)
		total += calculatePrice(cart->itemList[i]);
	return total;
}

void printCart(ShoppingCart* s) {
	printf("this cart has %d items:",s->amount);
	for (int i = 0; i < s->amount; i++)
		printItem(s->itemList[i]);
	printf("the total sum is:%f", s->price);
}