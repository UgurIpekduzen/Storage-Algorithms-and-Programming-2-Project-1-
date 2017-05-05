#pragma once
#include"Database.h"
#include"Operations.h"

class Interface
{
	Operations * operation;
	Database * database;
public:
	
	Interface(Database * DB, Operations *Op);
	~Interface(void);

	//Main Operations Menu
	void MainOperationsMenu();

	//Sub Menus
	void ListingEntityMenu();
	void RegisteringEntityMenu();
	void SearchingEntityMenu();

	//Entity Listing Screens
	void ListingUsersScreen();
	void ListingCustomersScreen();
	void ListingProductsScreen();
	void ListingOrdersScreen();
	void ListingCategoriesScreen();
	void ListingOrderDetailsScreen();

	//Entity Registering Screens
	void RegisterUserScreen();
	void RegisterCustomerScreen();
	void RegisterProductScreen();
	void RegisterOrderScreen();
	void RegisterCategoryScreen();
	void RegisterOrderDetailsScreen();

	//Find Entity Screens
	void FindUserScreen();
	void FindCustomerScreen();
	void FindProductScreen();
	void FindOrderScreen();
	void FindCategoryScreen();
	void FindOrderDetailsScreen();
	
	//Remove Entity Screens
	void RemoveUserScreen();
	void RemoveCustomerScreen();
	void RemoveProductScreen();
	void RemoveOrderScreen();
	void RemoveCategoryScreen();
	void RemoveOrderDetailsScreen();

	//Show Entity Screens
	void ShowUserScreen(User * user);
	void ShowCustomerScreen(Customer * customer);
	void ShowProductScreen(Product * product);
	void ShowOrderScreen(Order * order);
	void ShowCategoryScreen(Category * category);
	void ShowOrderDetailsScreen(OrderDetails * orderdetails);

	//Show Entity Methods
	void ShowUsers(list<User*>&list);
	void ShowCustomers(list<Customer*>&list);
	void ShowProducts(list<Product*>&list);
	void ShowOrders(list<Order*>&list);
	void ShowCategories(list<Category*>&list);
	void ShowOrderDetailss(list<OrderDetails*>&list);
	
	//Entity Editing Screens
	void EditUserScreen(User * Usr);
	void EditCustomerScreen(Customer * Cus);
	void EditProductScreen(Product * Prod);
	void EditOrderScreen(Order * Ord);
	void EditCategoryScreen(Category * Cat);
	void EditOrderDetailsScreen(OrderDetails * OrdDet);
};

