#include "shoppingItem.h"
#include "product.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void initItem(const Product* pP, const int amount, ShoppingItem* pSI) {
	pSI->amountInCart = amount;
	strcpy(pSI->barcode, pP->barcode);
	pSI->price = pP->price;
}
void printItem(const ShoppingItem* pSI) {
	printf("Item barcode: %s, price: %.2f, %d in cart",pSI->barcode,pSI->price,pSI->amountInCart);
}
float calculatePrice(const ShoppingItem* item) {
	return item->amountInCart * item->price;
}
void freeItem(ShoppingItem* item) {
	free(item);
}
int compareItemByBarcode(const void* a, const void* b)
{
	return (strcmp((*(ShoppingItem**)a)->barcode, (*(ShoppingItem**)b)->barcode));
}
ShoppingItem* getItemByBarcode(const ShoppingItem** itemList, const int itemAmount, const char* barcode)
{
	ShoppingItem item = { 0 };
	strcpy(item.barcode, barcode);
	qsort(itemList, itemAmount, sizeof(ShoppingItem*), compareItemByBarcode);
	return *(ShoppingItem**)bsearch(&item, itemList, itemAmount, sizeof(ShoppingItem), compareItemByBarcode);
}