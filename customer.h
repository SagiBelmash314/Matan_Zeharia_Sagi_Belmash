#pragma once
#include "shoppingCart.h"
#define ID_LEN 9
#define MAX_LEN 255

typedef struct {
	char	id[ID_LEN+1];
	char	name[MAX_LEN];
	shoppingCart	myCart;
}customer;

void initCustomer(customer* c);
char* setName();
void freeCustomer(customer* c);
void printCustomer(customer* c);