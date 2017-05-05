#include "Customer.h"

Customer::Customer(int cusID, string comName, string email,
	string conTitle, string address, string city,
	string region, string posCode, string country,
	string phone, string fax, string flag)
{
	CustomerID = cusID;
	CompanyName = comName;
	Email = email;
	ContactTitle = conTitle;
	Address = address;
	City = city;
	Region = region;
	PostalCode = posCode;
	Country = country;
	Phone = phone;
	Fax = fax;
	Flag = flag;
}

Customer::~Customer()
{
}
