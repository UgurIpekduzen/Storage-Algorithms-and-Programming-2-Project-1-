#pragma once
#include"include.h"
#include"Order.h"
#include"Category.h"
#include"User.h"
#include"Product.h"
#include"OrderDetails.h"
#include"Customer.h"

class Database
{
public:
	Database();
	~Database();

	list<User*>Users;
	list<Customer*>Customers;
	list<Order*>Orders;
	list<Category*>Categories;
	list<Product*>Products;
	list<OrderDetails*>OrderDetailss;

	list<int>OrderAndUser;
	list<int>OrderAndCustomer;
	list<int>ProductAndCategory;
	list<int>OrderDetailsAndProduct;
	list<int>OrderdetailsAndOrder;
	
	void Build();
	void Build(string UsrSrcFile, string CustSrcFile, string ProdSrcFile, string OrdSrcFile, string CatSrcFile, string OrdDetSrcFile);
	bool Save();
	bool Save(string UsrSrcFile, string CustSrcFile, string ProdSrcFile, string OrdSrcFile, string CatSrcFile, string OrdDetSrcFile);

	//Find Methods
	User * FindUser(int ID);
	Customer * FindCustomer(int ID);
	Order * FindOrder(int ID);
	Category * FindCategory(int ID);
	Product * FindProduct(int ID);
	OrderDetails * FindOrderDetails(int ID);

	//Remove Relationship Methods
	void RemoveRelationshipOrderandUser(User * usr);
	void RemoveRelationshipOrderandCustomer(Customer * cus);
	void RemoveRelationshipOrderDetailsAndProduct(Product * prod);
	void RemoveRelationshipOrderDetailsAndOrder(Order * ord);
	void RemoveRelationshipProductandCategory(Category * cat);
	
	private:
	// Data Installation Methods
	void ReadUsers(string UsrSrcFile);
	void ReadCustomers(string CustSrcFile);
	void ReadProducts(string ProdSrcFile);
	void ReadOrders(string OrdSrcFile);
	void ReadCategories(string CatSrcFile);
	void ReadOrderDetails(string OrdDetSrcFile);
	
	//Relate Methods
	void RelateOrderAndUser();
	void RelateOrderAndCustomer();
	void RelateProductAndCategory();
	void RelateOrderDetailsAndProduct();
	void RelateOrderDetailsAndOrder();
	
	//Save Methods
	bool SaveUser(string UsrSrcFile);
	bool SaveCustomer(string CustSrcFile);
	bool SaveProduct(string ProdSrcFile);
	bool SaveOrder(string OrdSrcFile);
	bool SaveCategory(string CatSrcFile);
	bool SaveOrderDetails(string OrdDetSrcFile);
};

