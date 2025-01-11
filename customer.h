#pragma once
#include "ShoppingCart.h"
#define ID_LEN 9
#define MAX_LEN 255

typedef struct {
	char	id[ID_LEN + 1];
	char	name[MAX_LEN];
	ShoppingCart* cart;
}Customer;

int initCustomer(Customer* c);
void freeCustomer(Customer* c);
void printCustomer(Customer* c);
int compareCustomerById(const void* a, const void* b);
int compareCustomerByName(const void* a, const void* b);
