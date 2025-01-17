#include "shoppingItem.h"
#include "product.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void initItem(Product* p, ShoppingItem* item) {
	puts("how much of this item? ");
	scanf("%d", &item->amountInCart);
	strcpy(item->barcode, p->barcode);
	item->price = p->price;
}
void printItem(Product* p) {
	printf("%s: price:%f, amount:%d, total:%f, barcode:%s, expiration date:", p->name, p->price, p->amount, (float)p->price * p->amount, p->barcode);
	printDate(p->expDate);
}
float calculatePrice(const ShoppingItem* item) {
	return item->amountInCart * item->price;
}
void freeItem(ShoppingItem* item) {
	free(item);
}
Product matchingProduct(ShoppingItem* item,Product* pProdList) {

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