#include "Operations.h"

Operations::Operations()
{
}

Operations::~Operations()
{
}

Operations::Operations(Database * DB) { database = DB; }

bool Operations::InsertUser(User * user) 
{
	database->Users.push_back(user);
	return true;
}
bool Operations::InsertCustomer(Customer * customer)
{ 
	database->Customers.push_back(customer);
	return true;
}
bool Operations::InsertProduct(Product * product)
{
	database->Products.push_back(product);
	return true;
}
bool Operations::InsertOrder(Order * order)
{ 
	database->Orders.push_back(order);
	return true;
}
bool Operations::InsertCategory(Category * category)
{ 
	database->Categories.push_back(category);
	return true;
}
bool Operations::InsertOrderDetails(OrderDetails * orderdetails)
{ 
	database->OrderDetailss.push_back(orderdetails);
	return true;
}

bool Operations::RemoveUser(int ID)
{
	list<User*>::iterator it;
	for (it = database->Users.begin();it != database->Users.end();it++)
	{
		if ((*it)->UserID == ID)
		{
			User * deleteThis = database->FindUser(ID);
			database->RemoveRelationshipOrderandUser(deleteThis);
			database->Users.erase(it);
			return true;
			break;
		}
	}
}
bool Operations::RemoveCustomer(int ID)
{
	list<Customer*>::iterator it;
	for (it = database->Customers.begin();it != database->Customers.end();it++)
	{
		if ((*it)->CustomerID == ID)
		{
			Customer * deleteThis = database->FindCustomer(ID);
			database->RemoveRelationshipOrderandCustomer(deleteThis);
			database->Customers.erase(it);
			return true;
			break;
		}
	}
}
bool Operations::RemoveProduct(int ID)
{
	list<Product*>::iterator it;
	for (it = database->Products.begin();it != database->Products.end();it++)
	{
		if ((*it)->ProductID == ID)
		{
			Product * deleteThis = database->FindProduct(ID);
			database->RemoveRelationshipOrderDetailsAndProduct(deleteThis);
			deleteThis->category = NULL;
			database->Products.erase(it);
			return true;
			break;
		}
	}
}
bool Operations::RemoveOrder(int ID)
{
	list<Order*>::iterator it;
	for (it = database->Orders.begin();it != database->Orders.end();it++)
	{
		if ((*it)->OrderID == ID)
		{	
			Order * deleteThis = database->FindOrder(ID);
			database->RemoveRelationshipOrderDetailsAndOrder(deleteThis);
			deleteThis->user = NULL;
			deleteThis->customer = NULL;
			database->Orders.erase(it);
			return true;
			break;
		}
	}
}
bool Operations::RemoveCategory(int ID)
{
	list<Category*>::iterator it;
	for (it = database->Categories.begin();it != database->Categories.end();it++)
	{
		if ((*it)->CatID == ID)
		{
			Category * deleteThis = database->FindCategory(ID);
			database->RemoveRelationshipProductandCategory(deleteThis);
			database->Categories.erase(it);
			return true;
			break;
		}
	}
}
bool Operations::RemoveOrderDetails(int ID)
{
	list<OrderDetails*>::iterator it;
	for (it = database->OrderDetailss.begin();it != database->OrderDetailss.end();it++)
	{
		if ((*it)->OrdDetID == ID)
		{
			OrderDetails * deleteThis = database->FindOrderDetails(ID);
			deleteThis->order = NULL;
			deleteThis->product = NULL;
			database->OrderDetailss.erase(it);
			return true;
			break;
		}
	}
}