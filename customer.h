#pragma once
#include "shoppingCart.h"
#include "general.h"
#define ID_LEN 9

typedef struct {
	char			id[ID_LEN + 1];
	char			name[MAX_LEN];
	ShoppingCart*	cart;
}Customer;

int			initCustomer(Customer* c);
void		freeCustomer(Customer* c);
void		printCustomer(const Customer* c);
int			compareCustomerById(const void* a, const void* b);
int			compareCustomerByName(const void* a, const void* b);
Customer*	getCustomerById(Customer* customerList, const int custAmount, const char* id);
Customer*	getCustomerByName(Customer* customerList, const int custAmount, const char* name);
