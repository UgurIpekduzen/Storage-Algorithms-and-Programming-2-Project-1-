#pragma once
#include"include.h"
#include"User.h"
#include"Customer.h"
#include"OrderDetails.h"

class User;
class Customer;
class OrderDetails;
class Order
{
public:
	int OrderID;
	DateTime OrderDate;
	DateTime RequiredDate;
	DateTime ShippedDate;
	string ShipVia;
	string ShipName;
	string ShipAddress;
	string ShipCity;
	string ShipRegion;
	int ShipPostalCode;
	string ShipCountry;
	string Flag;
	Customer *customer;
	User *user;
	list<OrderDetails*> orderdetailss;

	Order(int oID,string oDate,string rDate,string sDate,
		string sVia, string sName,
		string sAddress, string sCity, string sRegion,
		int sCode, string sCountry, string flag);

	~Order();
};

