#pragma once
#include"include.h"
#include"Category.h"
#include"OrderDetails.h"

class Category;
class OrderDetails;
class Product
{
public:
	int ProductID;
	string ProductName;
	Category * category; //CategoryID
	int QuantityPerUnit;
	float UnitPrice;
	int UnitsInStock;
	int UnitsOnDoor;
	list < OrderDetails*>orderdetailss;
	
	Product(int pID, string pName, int QPU, float uPrice, int UIS, int UOD);
	~Product();
};