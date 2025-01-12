#include <stdio.h>
#include "superMarket.h"
#define ERR_MSG "An error has accured"



void printMenu()
{
	puts("\n\nEnter the number of the desired action:");
	puts("1) Print supermarket details");
	puts("2) Add product");
	puts("3) Add customer");
	puts("4) Start buying");
	puts("5) Print shopping cart");
	puts("6) Manage shopping cart (make or cancel purchase)");
	puts("7) Print every product of a specific type");
	puts("8) Quit");
}

int invokeAction(SuperMarket* pSM, const int input)
{
	switch (input)
	{
		case 1: printSuperMarket(pSM); return 1;
		case 2: return addProduct(pSM);
		case 3: return addCustomer(pSM);
		case 4: return buy(pSM);
		case 5: return printCustomerCart(pSM);
		case 6: return manageCart(pSM);
		case 7: printProductsByType(pSM); return 1;
		case 8: return quit(pSM);
		default: puts("WTF?!?! WTF ARE YOU DOIN?!?! THIS IS WONG!!!"); return 1;
	}
}

void run(SuperMarket* pSM)
{

	int input, res;
	do
	{
		printMenu();
		scanf("%d", &input);
		clearBuffer();
		res = invokeAction(pSM, input);
		if (!res && input != 8)
		{
			puts(ERR_MSG);
			break;
		}
	} while (!(res == 0 && input == 8));
}

void main()
{
	SuperMarket sm;
	if (!initSuperMarket(&sm))
		puts(ERR_MSG);
	else run(&sm);
	puts("Goodbye!");
}