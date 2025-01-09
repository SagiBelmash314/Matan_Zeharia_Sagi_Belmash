#include <stdio.h>
#include "superMarket.h"
#define ERR_MSG "An error has accured"

void printMenu()
{
	puts("Enter the number of the desired action:");
	puts("1) Print supermarket details");
	puts("2) Add product");
	puts("3) Add customer");
	puts("4) Start buying");
	puts("5) Print shopping cart");
	puts("6) Manage shopping cart (make or cancel purchase)");
	puts("7) Print every product of a specific type");
	puts("8) Quit");
}

void quit(SuperMarket* pSM)
{

}

int invokeAction(SuperMarket* pSM, const int input)
{
	if (input == 1) printSuperMarket(pSM);
	else if (input == 2) addProduct(pSM);
	else if (input == 3) addCustomer(pSM);
	else if (input == 4) buy(pSM);
	else if (input == 5) printCart(pSM);
	else if (input == 6) manageCart(pSM);
	else if (input == 7) printProductsByType(pSM);
	else if (input == 8) quit(pSM);
	else puts("WTF?!?! WTF ARE YOU DOIN?!?! THIS IS WONG!!!");
}


void main()
{
	SuperMarket sm;
	int input;
	if (!initSuperMarket(&sm))
		puts(ERR_MSG);
	else while (1)
	{
		printMenu();
		scanf("%d", &input);
		if (!invokeAction(&sm, input))
		{
			puts("Goodbye!");
		}
	}
}