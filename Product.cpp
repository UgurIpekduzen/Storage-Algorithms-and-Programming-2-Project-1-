#include "Product.h"

Product::Product(int pID, string pName, int QPU, float uPrice, int UIS, int UOD)
{
	ProductID = pID;
	ProductName = pName;
	QuantityPerUnit = QPU;
	UnitPrice = uPrice;
	UnitsInStock = UIS;
	UnitsOnDoor = UOD;
}

Product::~Product()
{
}
