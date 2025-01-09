#include "customer.h"
#include "general.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void initCustomer(customer* c) {
	printf("please enter yoyr ID number: ");
	scanf("%s", c->id);
	char firstName[MAX_NAME_LEN];
	setName(firstName, "first");
	char lastName[MAX_NAME_LEN];
	setName(lastName, "last");
}
char* setName(char* name, char* type) {
	name = (char*)malloc(MAX_LEN);
	printf("please enter your ");
	printf("%s", type);
	printf(" name: ");
	fgets(name, MAX_LEN + 1, stdin);
	clearBuffer(name);
}
void freeCustomer(customer* c) {
	for (int i = 0; i < c->myCart->amount; i++){
		printf("%d",&c->myCart->itemList[i]);
	}
}
void printCustomer(customer* c) {
	printf("the costumer's name is %s\nHis ID is: %s\nhis shopping cart is",c->name,c->id);
	printCart(c->myCart);
}