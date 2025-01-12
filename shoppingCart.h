#pragma once
#include "shoppingItem.h"

typedef struct {
	ShoppingItem**	itemList;
	float			price;
	int				amount;
}ShoppingCart;

void	initCart(ShoppingCart* pCart);
int		addItemToCart(ShoppingItem* pSI, ShoppingCart* pCart);
float	calculateTotal(const ShoppingCart* pCart);
void	printCart(const ShoppingCart* pCart);
void	freeCart(ShoppingCart* pCart);


