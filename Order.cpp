#include "Order.h"

Order::Order(int oID, string oDate, string rDate, string sDate,
	string sVia, string sName,
	string sAddress, string sCity, string sRegion,
	int sCode, string sCountry, string flag)
{
	OrderID = oID;
	OrderDate.Day_Month_Year = oDate;
	RequiredDate.Day_Month_Year = rDate;
	ShippedDate.Day_Month_Year = sDate;
	ShipVia = sVia;
	ShipName = sName;
	ShipAddress = sAddress;
	ShipCity = sCity;
	ShipRegion = sRegion;
	ShipPostalCode = sCode;
	ShipCountry = sCountry;
	Flag = flag;
}

Order::~Order()
{
}
