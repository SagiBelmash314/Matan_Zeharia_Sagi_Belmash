#include "shoppingItem.h"
#include "product.h"
#include <stdlib.h>
#include <stdio.h>

int calculatePrice(const ShoppingItem* item) {
	return item->amount * item->price;
}
void initItem(Product* p, ShoppingItem* item) {
	puts("how much of this item? ");
	scanf("%d", &item->amount);
	strcpy(item->barcode, p->barcode);
	item->price = p->price;
}