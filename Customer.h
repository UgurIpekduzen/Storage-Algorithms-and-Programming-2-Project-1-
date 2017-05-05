#pragma once
#include"include.h"
#include"Order.h"
class Order;
class Customer
{
public:
	int CustomerID;
	string CompanyName;
	string Email;
	string ContactTitle;
	string Address;
	string City;
	string Region;
	string PostalCode;
	string Country;
	string Phone;
	string Fax;
	string Flag;
	list<Order*>Orders;

	Customer(int cusID, string comName, string email,
		string conTitle, string address, string city,
		string region, string posCode, string country,
		string phone, string fax, string flag);

	~Customer();
};