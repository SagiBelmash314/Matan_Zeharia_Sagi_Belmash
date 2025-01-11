#include "customer.h"
#include "general.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int initCustomer(Customer* c) {
	printf("please enter your ID number: ");
	scanf("%s", c->id);
	char* firstName = getStrFromUser("please enter your first name");
	toupper(firstName[0]);
	char* lastName = getStrFromUser("please enter your last name");
	toupper(lastName[0]);
	strcpy(c->name, firstName);
	strcat(c->name, lastName);
	initCart(c->cart);
}
void freeCustomer(Customer* c) {
	freeCart(c->cart);
	free(c);
}
void printCustomer(Customer* c) {
	printf("the costumer's name is %s\nHis ID is: %s\nhis shopping cart is",c->name,c->id);
	printCart(c->cart);
}
int compareCustomerById(const void* a, const void* b)
{
	return (strcmp(((Customer*)a)->id, ((Customer*)b)->id));
}

int compareCustomerByName(const void* a, const void* b)
{
	return (strcmp(((Customer*)a)->name, ((Customer*)b)->name));
}

Customer* getCustomerById(const Customer* customerList, const int custAmount, const char* id)
{
	Customer temp = { .id = id };
	qsort(customerList, custAmount, sizeof(Customer), compareCustomerById);
	Customer* pC = bsearch(&temp, customerList, custAmount, sizeof(Customer), compareCustomerById);
	return pC;
}