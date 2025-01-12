#include "customer.h"
#include "general.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int checkIdValidity(const char* id)
{
	for (int i = 0; i < ID_LEN; i++)
		if (id[i] < '0' || id[i] > '9')
		{
			puts("Id should only contain digits");
			return 0;
		}
	return 1;
}

int initCustomer(Customer* pC)
{
	do
	{
		puts("\nPlease enter 9 digit long ID number: ");
		fgets(pC->id, ID_LEN + 1, stdin);
	} while (strlen(pC->id) < ID_LEN || !checkIdValidity(pC->id));
	char* firstName = getStrFromUser("\nPlease enter the first name:");
	char* lastName = getStrFromUser("\nPlease enter the last name:");
	if (!firstName || !lastName)
		return 0;
	for(int i = 0; i < strlen(firstName); i++)
	{
		tolower(firstName[i]);
		tolower(lastName[i]);
	}
	toupper(firstName[0]);
	toupper(lastName[0]);
	pC->name = (char*)malloc(sizeof(char) * (strlen(firstName) + strlen(lastName) + 4));
	strcpy(pC->name, firstName);
	strcat(pC->name, " - ");
	strcat(pC->name, lastName);
	free(firstName);
	free(lastName);
	ShoppingCart cart;
	initCart(&cart);
	pC->cart = &cart;
	return 1;
}

void freeCustomer(Customer* pC)
{
	freeCart(pC->cart);
	free(pC);
}

void printCustomer(const Customer* pC)
{
	printf("The costumer's name is %s\nHis ID is: %s\nhis shopping cart is",pC->name,pC->id);
	printCart(pC->cart);
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
	return (Customer*)bsearch(&temp, customerList, custAmount, sizeof(Customer), compareCustomerById);
}

Customer* getCustomerByName(Customer* customerList, const int custAmount, const char* name)
{
	Customer temp = { 0 };
	strcpy(temp.name, name);
	qsort(customerList, custAmount, sizeof(Customer), compareCustomerByName);
	return (Customer*)bsearch(&temp, customerList, custAmount, sizeof(Customer), compareCustomerByName);
}