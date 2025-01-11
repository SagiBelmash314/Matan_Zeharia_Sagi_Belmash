#include "customer.h"
#include "general.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int initCustomer(Customer* c) {
	puts("Please enter your ID number: ");
	scanf("%s", c->id);
	char* firstName = getStrFromUser("Please enter your first name:");
	char* lastName = getStrFromUser("Please enter your last name:");
	if (!firstName || !lastName)
		return 0;
	for(int i = 0;i<strlen(firstName);i++){
		tolower(firstName[i]);
		tolower(lastName[i]);
	}
	toupper(firstName[0]);
	toupper(lastName[0]);
	strcpy(c->name, firstName);
	strcat(c->name, " - ");
	strcat(c->name, lastName);
	initCart(c->cart);
	return 1;
}

void freeCustomer(Customer* c) {
	freeCart(c->cart);
	free(c);
}

void printCustomer(const Customer* c) {
	printf("The costumer's name is %s\nHis ID is: %s\nhis shopping cart is",c->name,c->id);
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
 
Customer* getCustomerById(Customer* customerList, const int custAmount, const char* id)
{
	Customer temp = { 0 };
	strcpy(temp.id, id);
	qsort(customerList, custAmount, sizeof(Customer), compareCustomerById);
	Customer* pC = bsearch(&temp, customerList, custAmount, sizeof(Customer), compareCustomerById);
	return pC;
}

Customer* getCustomerByName(Customer* customerList, const int custAmount, const char* name)
{
	Customer temp = { 0 };
	strcpy(temp.name, name);
	qsort(customerList, custAmount, sizeof(Customer), compareCustomerByName);
	Customer* pC = bsearch(&temp, customerList, custAmount, sizeof(Customer), compareCustomerByName);
	return pC;
}