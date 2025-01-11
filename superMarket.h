#pragma once
#include "customer.h"

typedef struct 
{
	char*		name;
	Customer*	customerList;
	int			custAmount;
	Product**	productList;
	int			prodAmount;
} SuperMarket;

int		initSuperMarket(SuperMarket* pSM);
void	printSuperMarket(const SuperMarket* pSM);
int		addProduct(SuperMarket* pSM);
int		addCustomer(SuperMarket* pSM);
int		buy(SuperMarket* pSM);
int		printCustomerCart(SuperMarket* pSM);
int		manageCart(SuperMarket* pSM);
void	printProductsByType(const SuperMarket* pSM);
int		quit(SuperMarket* pSM);
