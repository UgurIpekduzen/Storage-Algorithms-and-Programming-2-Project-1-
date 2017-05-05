#pragma once
#include"include.h"
#include"Order.h"

class Order;
class User
{
public:
	int UserID;
	string Name;
	string Email;
	string Address;
	string Phone;
	list<Order*>Orders;
	string Password;

	User(int userId, string name, string email, string address, string phone, string password);
	~User();
};