#include "OrderDetails.h"

OrderDetails::OrderDetails(int ODID,float uPrice, int quantity, int discount)
{
	OrdDetID = ODID;
	UnitPrice = uPrice;
	Quantity = quantity;
	Discount = discount;
}

OrderDetails::~OrderDetails()
{
}
