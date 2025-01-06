#include "customer.h"
#include "general.h"
#include <stdio.h>
#include <stdlib.h>


void initCustomer(customer* c) {
	printf("please enter yoyr ID number: ");
	scanf("%s", c->id);
	char* firstName;
	setName(firstName,"first");
	char* lastName;
	setName(lastName,"last");
}
char* setName(char* name,char* type) {
	name = (char*)malloc(MAX_LEN);
	printf("please enter your ");
	printf("%s", type);
	printf(" name: ");
	fgets(name, MAX_LEN + 1, stdin);
	clearBuffer(name);
}
void freeCustomer(customer* c);
void printCustomer(customer* c);