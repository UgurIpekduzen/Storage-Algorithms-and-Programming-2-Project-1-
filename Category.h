#pragma once
#include"include.h"
#include"Product.h"

class Product;
class Category
{
public:
	int CatID;
	string CategoryName;
	string Description;
	list<Product*>Products;
	
	Category(int catID, string catName, string desc);
	~Category();
};

