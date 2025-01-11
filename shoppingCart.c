#include <stdlib.h>
#include <stdio.h>
#include "ShoppingCart.h"
#include "general.h"

void initCart(ShoppingCart* pCart) {
	pCart->itemList = NULL;
	pCart->amount = 0;
	pCart->price = 0;
}

int addItemToCart(ShoppingItem* pSI, ShoppingCart* pCart) {
	pCart->amount += 1;
	pCart->itemList = (ShoppingItem**)safeRealloc(pCart->itemList,pCart->amount * (sizeof(ShoppingItem*)));
	if (!pCart->itemList)
		return 0;
	pCart->itemList[pCart->amount - 1] = pSI;
	return 1;
}
float calculateTotal(const ShoppingCart* pCart) {
	float total = 0;
	for (int i = 0; i < pCart->amount; i++)
		total += calculatePrice(pCart->itemList[i]);
	return total;
}

void printCart(const ShoppingCart* pCart) {
	printf("This pCart has %d items:", pCart->amount);

	for (int i = 0; i < pCart->amount; i++)
		printItem(pCart->itemList[i]);
	printf("The total sum is: %.2f", pCart->price);
}

void freeCart(ShoppingCart* pCart) {
	for (int i = 0; i < pCart->amount; i++)
		freeItem(pCart->itemList[i]);
	free(pCart);
}