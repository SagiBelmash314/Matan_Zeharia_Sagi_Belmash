#pragma once
#include "customer.h"

// Delete
#include "product.h"

typedef struct 
{
	char* name;
	Customer* customerList;
	int custAmount;
	Product** productList;
	int prodAmount;
} SuperMarket;

int		initSuperMarket(SuperMarket* pSM);
void	printSuperMarket(const SuperMarket* pSM);
int		addProduct(SuperMarket* pSM);
int		addCustomer(SuperMarket* pSM);
int		buy(SuperMarket* pSM);
int		purchase(SuperMarket* pSM);
int		cancel(SuperMarket* pSM);
void	printProductsByType(const SuperMarket* pSM);
void	freeSuperMarket(SuperMarket* pSM);
