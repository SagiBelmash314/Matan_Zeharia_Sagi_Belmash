#include "shoppingItem.h"
#include "product.h"
#include <stdlib.h>
#include <stdio.h>

int calculatePrice(const shoppingItem* item) {
	return item->amount * item->price;
}
void initItem(Product* p, shoppingItem* item) {
	puts("how much of this item? ");
	scanf("%d", &item->amount);
	strcpy(item->barcode, p->barcode);
	item->price = p->price;
}