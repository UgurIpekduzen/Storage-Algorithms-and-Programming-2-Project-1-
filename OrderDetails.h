#pragma once
#include"include.h"
#include"Order.h"
#include"Product.h"
class Order;
class Product;
class OrderDetails
{
public:
	int OrdDetID; //Benim eklemem
	Product *product;
	Order * order;
	float UnitPrice;
	int Quantity;
	int Discount;//Yüzde olarak
	
	OrderDetails(int ODID,float uPrice, int quantity, int discount);
	~OrderDetails();
};
