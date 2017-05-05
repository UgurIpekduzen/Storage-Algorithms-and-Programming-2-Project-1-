#pragma once
#include"Database.h"
	class Operations
{
public:
	Operations();
	~Operations();

	Database * database;
	Operations(Database * DB);
	
	bool InsertUser(User * user);
	bool InsertCustomer(Customer * customer);
	bool InsertProduct(Product * product);
	bool InsertOrder(Order * order);
	bool InsertCategory(Category * category);
	bool InsertOrderDetails(OrderDetails * orderdetails);

	bool RemoveUser(int ID);
	bool RemoveCustomer(int ID);
	bool RemoveProduct(int ID);
	bool RemoveOrder(int ID);
	bool RemoveCategory(int ID);
	bool RemoveOrderDetails(int ID);
};

