#include"Interface.h"

Interface::Interface(Database * DB, Operations *Op)
{
	database = DB;
	operation = Op;
}

Interface::~Interface()
{
}

//Main Operations Menu
void Interface::MainOperationsMenu()
{
	while(true)
	{
		cout << "Main Operations Menu" << endl
			<< "0 - Exit" << endl
			<< "1 - Listing and Removing Sub Menu" << endl
			<< "2 - Searching Sub Menu" << endl
			<< "3 - Registering Sub Menu" << endl
			<< "4 - Save" << endl
			<< "-------------------" << endl
			<< "Enter one of these numbers: ";

		int InputKey;
		cin >> InputKey;
		while (InputKey != 1 && InputKey != 2 && InputKey != 3 && InputKey != 4 && InputKey != 0)	cin >> InputKey;

		system("CLS");
		switch (InputKey)
		{
		case 0:
			exit(0);
			break;
		case 1:
			ListingEntityMenu();
			break;
		case 2:
			SearchingEntityMenu();
			break;
		case 3:
			RegisteringEntityMenu();
			break;
		case 4:
			database->Save();
			cout << "Saved successfully." << endl;
			system("pause");
			break;
		}
		system("CLS");
	}
}

//Sub Menus
void Interface::ListingEntityMenu()
{
	cout << "Entity Listing Menu" << endl << endl
		 << "0 - Main Operations Menu" << endl
		 << "1 - Listing User" << endl
		 << "2 - Listing Customer" << endl
		 << "3 - Listing Product" << endl
		 << "4 - Listing Order" << endl
		 << "5 - Listing Category" << endl
		 << "6 - Listing Order Details" << endl;
	
	int InputKey;
	cin >> InputKey;
	while (InputKey != 0 && InputKey != 1 && InputKey != 2
				&& InputKey != 3 && InputKey != 4 
					&& InputKey != 5 && InputKey != 6)	cin >> InputKey;
	system("CLS");
	
	switch (InputKey)
	{
	case 0:
		MainOperationsMenu();
		break;
	case 1:
		ListingUsersScreen();
		break;
	case 2:
		ListingCustomersScreen();
		break;
	case 3:
		ListingProductsScreen();
		break;
	case 4:
		ListingOrdersScreen();
		break;
	case 5:
		ListingCategoriesScreen();
		break;
	case 6:
		ListingOrderDetailsScreen();
		break;
	}
}
void Interface::RegisteringEntityMenu()
{
	cout << "Registering Entity Menu" << endl << endl
	     << "0 - Main Operations Menu" << endl
		 << "1 - Register User" << endl
		 << "2 - Register Customer" << endl
		 << "3 - Register Product" << endl
		 << "4 - Register Order" << endl
		 << "5 - Register Category" << endl
		 << "6 - Register Order Details" << endl<< endl
		 << "It is recommended that you follow this sequence when registering!" << endl << endl
		 << "             |--> Product --> Category" << endl
		 << "             |" << endl
		 << "Order Details          |--> User" << endl
		 << "             |--> Order " << endl
		 << "                       |--> Customer" << endl;
	//Kullanýcý giriþi beklenir
	int InputKey;
	cin >> InputKey;
	while (InputKey != 0 && InputKey != 1 && InputKey != 2
				&& InputKey != 3 && InputKey != 4
					&& InputKey != 5 && InputKey != 6)	cin >> InputKey;
	system("CLS");

	switch (InputKey)
	{
	case 0:
		MainOperationsMenu();
		break;
	case 1:
		RegisterUserScreen();
		break;
	case 2:
		RegisterCustomerScreen();
		break;
	case 3:
		RegisterProductScreen();
		break;
	case 4:
		RegisterOrderScreen();
		break;
	case 5:
		RegisterCategoryScreen();
		break;
	case 6:
		RegisterOrderDetailsScreen();
		break;
	}
}
void Interface::SearchingEntityMenu()
{
	cout << "Searching Entity Menu" << endl << endl
		 << "0 - Main Operations Menu" << endl
		 << "1 - Find User" << endl
		 << "2 - Find Customer" << endl
		 << "3 - Find Product" << endl
		 << "4 - Find Order" << endl
		 << "5 - Find Category" << endl
		 << "6 - Find OrderDetails" << endl;
	int InputKey;
	cin >> InputKey;
	while (InputKey != 0 && InputKey != 1 && InputKey != 2
				&& InputKey != 3 && InputKey != 4
					&& InputKey != 5 && InputKey != 6)	cin >> InputKey;
	system("CLS");
	switch (InputKey)
	{
	case 0:
		MainOperationsMenu();
		break;
	case 1:
		FindUserScreen();
		break;
	case 2:
		FindCustomerScreen();
		break;
	case 3:
		FindProductScreen();
		break;
	case 4:
		FindOrderScreen();
		break;
	case 5:
		FindCategoryScreen();
		break;
	case 6:
		FindOrderDetailsScreen();
		break;
	}
}

//Entity Listing Screens
void Interface::ListingUsersScreen()
{
	while (true)
	{
		ShowUsers(database->Users);

		cout << "-------------------" << endl
		     << "0 - Main Operations Menu" << endl
			 << "1 - Remove a User" << endl
			 << "2 - Back to the Previous Menu" << endl;
		
		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1 && InputKey != 2)	cin >> InputKey;
		system("CLS");
		
		switch (InputKey)
		{
		case 0:
			MainOperationsMenu();
			break;
		case 1:
			RemoveUserScreen();
			break;
		case 2:
			ListingEntityMenu();
			break;
		}
	}
}
void Interface::ListingCustomersScreen()
{
	while (true)
	{
		ShowCustomers(database->Customers);

		cout << "-------------------" << endl
		     << "0 - Main Operations Menu" << endl
			 << "1 - Remove a Customer" << endl
			 << "2 - Back to the Previous Menu" << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1 && InputKey != 2)	cin >> InputKey;
		system("CLS");

		switch (InputKey)
		{
		case 0:
			MainOperationsMenu();
			break;
		case 1:
			RemoveCustomerScreen();
			break;
		case 2:
			ListingEntityMenu();
			break;
		}
	}
}
void Interface::ListingProductsScreen()
{
	while (true)
	{
		ShowProducts(database->Products);

		cout << "-------------------" << endl
		     << "0 - Main Operations Menu" << endl
		     << "1 - Remove a Product" << endl
			 << "2 - Back to the Previous Menu" << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1 && InputKey != 2)	cin >> InputKey;
		system("CLS");

		switch (InputKey)
		{
		case 0:
			MainOperationsMenu();
			break;
		case 1:
			RemoveProductScreen();
			break;
		case 2:
			ListingEntityMenu();
			break;
		}
	}
}
void Interface::ListingOrdersScreen()
{
	while (true)
	{
		ShowOrders(database->Orders);

		cout << "-------------------" << endl
		     << "0 - Main Operations Menu" << endl
			 << "1 - Remove a Order" << endl
			 << "2 - Back to the Previous Menu" << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1 && InputKey != 2)	cin >> InputKey;
		system("CLS");

		switch (InputKey)
		{
		case 0:
			MainOperationsMenu();
			break;
		case 1:
			RemoveOrderScreen();
			break;
		case 2:
			ListingEntityMenu();
			break;
		}
	}
}
void Interface::ListingCategoriesScreen()
{
	while (true)
	{
		ShowCategories(database->Categories);

		cout << "-------------------" << endl
		     << "0 - Main Operations Menu" << endl
		     << "1 - Remove a Category" << endl
			 << "2 - Back to the Previous Menu" << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1 && InputKey != 2)	cin >> InputKey;
		system("CLS");

		switch (InputKey)
		{
		case 0:
			MainOperationsMenu();
			break;
		case 1:
			RemoveCategoryScreen();
			break;
		case 2:
			ListingEntityMenu();
			break;
		}
	}
}
void Interface::ListingOrderDetailsScreen()
{
	while (true)
	{
		ShowOrderDetailss(database->OrderDetailss);

		cout << "-------------------" << endl
		     << "0 - Main Operations Menu" << endl
		     << "1 - Remove Order Details" << endl
			 <<  "2 - Back to the Previous Menu" << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1 && InputKey != 2)	cin >> InputKey;
		system("CLS");

		switch (InputKey)
		{
		case 0:
			MainOperationsMenu();
		case 1:
			RemoveOrderDetailsScreen();
			break;
		case 2:
			ListingEntityMenu();
			break;
		}
	}
}

//Entity Inserting Screens
void Interface::RegisterUserScreen()
{
	cout << "You are going to insert a new user." << endl;
	//Boþ bir user oluþturulur
	User *newUser = new User(-1, "", "", "", "", "");
	//Boþ user varlýk düzenle ekranýna verilir
	EditUserScreen(newUser);
	//Bilgileri düzenlenen user ana listeye eklenir
	database->Users.push_back(newUser);
}
void Interface::RegisterCustomerScreen()
{
	cout << "You are going to insert a new customer." << endl;
	//Boþ bir Customer oluþturulur
	Customer *newCustomer = new Customer(-1, "", "", "", "", "","","","","","","");
	//Boþ Customer varlýk düzenle ekranýna verilir
	EditCustomerScreen(newCustomer);
	//Bilgileri düzenlenen Customer ana listeye eklenir
	database->Customers.push_back(newCustomer);
}
void Interface::RegisterProductScreen()
{
	cout << "You are going to insert a new product." << endl;
	//Boþ bir Product oluþturulur
	Product *newProduct = new Product(-1, "", -1, -1, -1, -1);
	//Boþ Product varlýk düzenle ekranýna verilir
	EditProductScreen(newProduct);
	//Bilgileri düzenlenen Product ana listeye eklenir
	database->Products.push_back(newProduct);
}
void Interface::RegisterOrderScreen()
{
	cout << "You are going to insert a new order." << endl;
	//Boþ bir Order oluþturulur
	Order *newOrder = new Order(-1, "", "", "", "", "", "", "", "", -1, "", "");
	//Boþ Order varlýk düzenle ekranýna verilir
	EditOrderScreen(newOrder);
	//Bilgileri düzenlenen Order ana listeye eklenir
	database->Orders.push_back(newOrder);
}
void Interface::RegisterCategoryScreen()
{
	cout << "You are going to insert a new category." << endl;
	//Boþ bir Category oluþturulur
	Category *newCategory = new Category(-1, "", "");
	//Boþ Category varlýk düzenle ekranýna verilir
	EditCategoryScreen(newCategory);
	//Bilgileri düzenlenen Category ana listeye eklenir
	database->Categories.push_back(newCategory);
}
void Interface::RegisterOrderDetailsScreen()
{
	cout << "You are going to insert new Order Details." << endl;
	//Boþ bir OrderDetails oluþturulur
	OrderDetails *newOrderDetails = new OrderDetails(-1, -1, -1, -1);
	//Boþ OrderDetails varlýk düzenle ekranýna verilir
	EditOrderDetailsScreen(newOrderDetails);
}

//Find Entity Screens
void Interface::FindUserScreen()
{
	while (true)
	{
		cout << "0 - Back to the Previous Menu " << endl
			<< "1 - User ID Entry " << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");

		switch (InputKey)
		{
		case 0:
			SearchingEntityMenu();
			break;
		case 1:
			int userID;
			cout << "Enter The User ID:";
			cin >> userID;

			while (!(userID > 0) && userID == 0)
			{
				cout << "You entered the wrong ID!" << endl;
				cin >> userID;
			}

			if (userID > 0)
			{
				User* user = database->FindUser(userID);
				if (user != NULL)
				{
					//Düzgün bir ID girilmiþ demektir
					ShowUserScreen(user);
				}
				else	cout << "No registeration found." << endl;
			}
			else	cout << "You entered the wrong ID!" << endl;
			break;
		}
	}
}
void Interface::FindCustomerScreen()
{
	while(true)
	{ 
		cout << "0 - Back to the Previous Menu" << endl
			<< "1 - Customer ID Entry " << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");

		switch (InputKey)
		{
		case 0:
			SearchingEntityMenu();
			break;
		case 1:
			int customerID;
			cout << "Enter The Customer ID:";
			cin >> customerID;

			while (!(customerID > 0) && customerID == 0)
			{
				cout << "You entered the wrong ID!" << endl;
				cin >> customerID;
			}

			if (customerID > 0)
			{
				Customer* customer = database->FindCustomer(customerID);
				if (customer != NULL)
				{
					//Düzgün bir ID girilmiþ demektir
					ShowCustomerScreen(customer);
				}
				else	cout << "No registeration found." << endl;
			}
			else	cout << "You entered the wrong ID!" << endl;
			break;
		}
	}
}
void Interface::FindProductScreen()
{
	while (true)
	{
		cout << "0 - Back to the Previous Menu " << endl
			<< "1 - Product ID Entry " << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");

		switch (InputKey)
		{
		case 0:
			SearchingEntityMenu();
			break;
		case 1:
			int prodID;
			cout << "Enter The Product ID:";
			cin >> prodID;

			while (!(prodID > 0) && prodID == 0)
			{
				cout << "No registeration found." << endl;
				cin >> prodID;
			}

			if (prodID > 0)
			{
				Product* product = database->FindProduct(prodID);
				if (product != NULL)
				{
					//Düzgün bir ID girilmiþ demektir
					ShowProductScreen(product);
				}
				else	cout << "No registeration found." << endl;
			}
			else	cout << "You entered the wrong ID!" << endl;
			break;
		}
	}
}
void Interface::FindOrderScreen()
{
	while (true)
	{
		cout << "0 - Back to the Previous Menu " << endl
			<< "1 - Order ID Entry " << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");
		switch (InputKey)
		{
		case 0:
			SearchingEntityMenu();
			break;
		case 1:
			int orderID;
			cout << "Enter The Order ID:";
			cin >> orderID;

			while (!(orderID > 0) && orderID == 0)
			{
				cout << "You entered the wrong ID!" << endl;
				cin >> orderID;
			}

			if (orderID > 0)
			{
				Order* order = database->FindOrder(orderID);
				if (order != NULL)
				{
					//Düzgün bir ID girilmiþ demektir
					ShowOrderScreen(order);
				}
				else	cout << "No registeration found." << endl;
			}
			else	cout << "You entered the wrong ID!" << endl;
			break;
		
		}
	}
}
void Interface::FindCategoryScreen()
{
	while (true)
	{
		cout << "0 - Back to the Previous Menu " << endl
			<< "1 - Category ID Entry " << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");

		switch (InputKey)
		{
		case 0:
			SearchingEntityMenu();
			break;
		case 1:
			int categoryID;
			cout << "Enter The Category ID:";
			cin >> categoryID;

			while (!(categoryID > 0) && categoryID == 0)
			{
				cout << "You entered the wrong ID!" << endl;
				cin >> categoryID;
			}

			if (categoryID > 0)
			{
				Category* category = database->FindCategory(categoryID);
				if (category != NULL)
				{
					//Düzgün bir ID girilmiþ demektir
					ShowCategoryScreen(category);
				}
				else	cout << "No registeration found." << endl;
			}
			else	cout << "You entered the wrong ID!" << endl;
			break;
		}
	}
}
void Interface::FindOrderDetailsScreen()
{
	while (true)
	{
		cout << "0 - Back to the Previous Menu " << endl
			<< "1 - Order Details ID Entry " << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");
		switch (InputKey)
		{
		case 0:
			SearchingEntityMenu();
			break;
		case 1:
			int OrdDetID;
			cout << "Enter The Order Details ID:";
			cin >> OrdDetID;

			while (!(OrdDetID > 0) && OrdDetID == 0)
			{
				cout << "You entered the wrong ID!" << endl;
				cin >> OrdDetID;
			}

			if (OrdDetID > 0)
			{
				OrderDetails * OrdDet = database->FindOrderDetails(OrdDetID);
				if (OrdDet != NULL)
				{
					//Düzgün bir ID girilmiþ demektir
					ShowOrderDetailsScreen(OrdDet);
				}
				else	cout << "No registeration found." << endl;
			}
			else	cout << "You entered the wrong ID!" << endl;
			break;
		}
	}
}

//Remove Entity Screens
void Interface::RemoveUserScreen()
{
	cout << "Enter the User ID that will be removed: " << endl;
	int ID;
	cin >> ID;

	if (operation->RemoveUser(ID) == false)
	{
		cout << "It could not remove! Be sure that the ID belongs to the list" << endl;
		_getch();
		system("CLS");	
	}
	else
	{
		cout << "The User removed successfully. " << endl;
		_getch();
		system("CLS");
	}
}
void Interface::RemoveCustomerScreen()
{
	cout << "Enter the Customer ID that will be removed: " << endl;
	int ID;
	cin >> ID;
	if (operation->RemoveCustomer(ID) == false)
	{
		cout << "It could not remove! Be sure that the ID belongs to the list" << endl;
		_getch();
		system("CLS");
	}

	else
	{
		cout << "The Customer removed successfully. " << endl;
		_getch();
		system("CLS");
	}
}
void Interface::RemoveProductScreen()
{
	cout << "Enter the Product ID that will be removed: " << endl;
	int ID;
	cin >> ID;
	if (operation->RemoveProduct(ID) == false)
	{
		cout << "It could not remove! Be sure that the ID belongs to the list" << endl;
		_getch();
		system("CLS");
	}
	else
	{
		cout << "The Product removed successfully. " << endl;
		_getch();
		system("CLS");
	}
}
void Interface::RemoveOrderScreen()
{
	cout << "Enter the Order ID that will be removed: " << endl;
	int ID;
	cin >> ID;
	if (operation->RemoveOrder(ID) == false) 
	{ 
		cout << "It could not remove! Be sure that the ID belongs to the list" << endl;
		_getch();
		system("CLS");
	}

	else
	{
		cout << "The Order removed successfully. " << endl;
		_getch();
		system("CLS");
	}
}
void Interface::RemoveCategoryScreen()
{
	cout << "Enter the Category ID that will be removed: " << endl;
	int ID;
	cin >> ID;
	if (operation->RemoveCategory(ID) == false)
	{
		cout << "It could not remove! Be sure that the ID belongs to the list" << endl;
		_getch();
		system("CLS");
	}
	else
	{
		cout << "The Category removed successfully. " << endl;
		_getch();
		system("CLS");
	}
}
void Interface::RemoveOrderDetailsScreen() 
{
	cout << "Enter the Order Details ID that will be removed: " << endl;
	int ID;
	cin >> ID;
	if (operation->RemoveOrderDetails(ID) == false)
	{
		cout << "It could not remove! Be sure that the ID belongs to the list" << endl;
		_getch();
		system("CLS");
	}
	else
	{
		cout << "The Order Details removed successfully. " << endl;
		_getch();
		system("CLS");
	}
}

//Show Entity Screens
void Interface::ShowUserScreen(User * user)
{
	if (user != NULL)
	{
		cout << "Id       : " << user->UserID << endl
			<< "Name     : " << user->Name << endl
			<< "Email    : " << user->Email << endl
			<< "Address  : " << user->Address << endl
			<< "Phone    : " << user->Phone << endl
			<< "Password : " << user->Password << endl << endl;

		while (true)
		{
			cout << "0 - Main Operations Menu" << endl
				 << "1 - See Orders of the User" << endl;
			
			int InputKey;
			cin >> InputKey;
			while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
			switch(InputKey)
			{
			case 0:
				system("CLS");
				MainOperationsMenu();
				break;
			case 1:
				cout << "Orders of the User" << endl;
				ShowOrders(user->Orders);
				break;
			}
		}
	}
}
void Interface::ShowCustomerScreen(Customer * customer)
{
	if (customer != NULL)
	{
		cout << "Id            : " << customer->CustomerID << endl
			 << "Company Name  : " << customer->CompanyName << endl
		     << "Email         : " << customer->Email << endl
			 << "Contact Title : " << customer->ContactTitle << endl
			 << "Address       : " << customer->Address << endl
			 << "City          : " << customer->City << endl
			 << "Region        : " << customer->Region << endl
			 << "Postal Code   : " << customer->PostalCode << endl
			 << "Country       : " << customer->Country << endl
			 << "Phone         : " << customer->Phone << endl
			 << "Fax           : " << customer->Fax << endl
			 << "Flag          : " << customer->Flag << endl << endl;

		while (true)
		{
			cout << "0 - Main Operations Menu" << endl
				 << "1 - See Orders of the Customer" << endl;

			int InputKey;
			cin >> InputKey;
			while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
			switch (InputKey)
			{
			case 0:
				system("CLS");
				MainOperationsMenu();
				break;
			case 1:
				cout << "Orders of the Customer" << endl;
				ShowOrders(customer->Orders);
				break;
			}
		}
	}
}
void Interface::ShowProductScreen(Product * product)
{
	if (product != NULL)
	{
		cout << "Id                : " << product->ProductID << endl
			 << "Name              : " << product->ProductName << endl
			 << "Quantity Per Unit : " << product->QuantityPerUnit << endl
			 << "Unit Price        : " << product->UnitPrice << endl
			 << "Units On Stock    : " << product->UnitsInStock << endl
			 << "Units On Door     : " << product->UnitsOnDoor << endl << endl;

		while (true)
		{
			cout << "0 - Main Operations Menu" << endl
				<< "1 - See Order Details of the Product" << endl;

			int InputKey;
			cin >> InputKey;
			while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
			switch (InputKey)
			{
			case 0:
				system("CLS");
				MainOperationsMenu();
				break;
			case 1:
				cout << "Order Details of the Product" << endl;
				ShowOrderDetailss(product->orderdetailss);
				break;
			}
		}
	}
}
void Interface::ShowOrderScreen(Order * order)
{
	if (order != NULL)
	{
		cout << "Id               : " << order->OrderID << endl
			 << "Ordered Date     : " << order->OrderDate.Day_Month_Year << endl
			 << "Required Date    : " << order->RequiredDate.Day_Month_Year << endl
			 << "Shipped Date     : " << order->ShippedDate.Day_Month_Year << endl
			 << "Ship Via         : " << order->ShipVia << endl
			 << "Ship Name        : " << order->ShipName << endl
			 << "Ship Address     : " << order->ShipAddress << endl
			 << "Ship City        : " << order->ShipCity << endl
			 << "Ship Region      : " << order->ShipRegion << endl
			 << "Ship Postal Code : " << order->ShipPostalCode << endl
			 << "Ship Country     : " << order->ShipCountry << endl
			 << "Flag             : " << order->Flag << endl << endl;

		while (true)
		{
			cout << "0 - Main Operations Menu" << endl
				<< "1 - See Order Details of the Order" << endl;

			int InputKey;
			cin >> InputKey;
			while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
			switch (InputKey)
			{
			case 0:
				system("CLS");
				MainOperationsMenu();
				break;
			case 1:
				cout << "Order Details of the Order" << endl;
				ShowOrderDetailss(order->orderdetailss);
				break;
			}
		}
	}
}
void Interface::ShowCategoryScreen(Category * category)
{
	if (category != NULL)
	{
		cout << "Id            : " << category->CatID << endl
			 << "Category Name : " << category->CategoryName << endl
		     << "Description   : " << category->Description << endl << endl;

		while (true)
		{
			cout << "0 - Main Operations Menu" << endl
				 << "1 - See Products of the Category" << endl;

			int InputKey;
			cin >> InputKey;
			while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
			switch (InputKey)
			{
			case 0:
				system("CLS");
				MainOperationsMenu();
				break;
			case 1:
				cout << "Products of the Category" << endl;
				ShowProducts(category->Products);
				break;
			}
		}
	}
}
void Interface::ShowOrderDetailsScreen(OrderDetails * orderdetails)
{
	if (orderdetails != NULL)
	{
		cout << "ID        : " << orderdetails->OrdDetID << endl
			<< "Unit Price : " << orderdetails->UnitPrice << endl
			<< "Quantity   : " << orderdetails->Quantity << endl
		    << "Discount   : " << orderdetails->Discount << endl << endl;

		while (true)
		{
			cout << "0 - Main Operations Menu" << endl;
			int InputKey;
			cin >> InputKey;
			while (InputKey != 0)	cin >> InputKey;
			switch (InputKey)
			{
			case 0:
				system("CLS");
				MainOperationsMenu();
				break;
			}
		}
	}
}

void Interface::ShowUsers(list<User*>&usr)
{
	cout << "ID		Name	Email	Adress	Phone	Password" << endl;
	list<User*>::iterator it;
	string tab = "		";
	for (it = usr.begin(); it != usr.end(); it++)
	{
		if ((*it) != NULL) 
			cout << (*it)->UserID << tab << (*it)->Name << tab << (*it)->Email << tab << (*it)->Address 
			<< tab << (*it)->Phone << tab << (*it)->Password << endl;
		else cout << "No Registeration Found!" << endl;
	}
}
void Interface::ShowCustomers(list<Customer*>&cus)
{
	cout << "ID		CompanyName	 Email	ContactTitle	Address	City	Region	PostalCode	Country		Phone	Fax	Flag" << endl;
	list<Customer*>::iterator it;
	string tab = "		";
	for (it = cus.begin(); it != cus.end(); it++)
	{
		if ((*it) != NULL) cout << (*it)->CustomerID << tab << (*it)->CompanyName << tab << (*it)->Email
			<< tab << (*it)->ContactTitle << tab << (*it)->Address << tab << (*it)->City << tab << (*it)->Region
			<< tab << (*it)->PostalCode << tab << (*it)->Country << tab << (*it)->Phone << tab << (*it)->Fax << (*it)->Flag << endl;
		
		else cout << "No Registeration Found!" << endl;
	}
}
void Interface::ShowProducts(list<Product*>&prod)
{
	cout << "ID		Name	QuantityPerUnit	Unit Price		UnitsInStock		UnitsOnDoor" << endl;
	list<Product*>::iterator it;
	string tab = "		";
	for (it = prod.begin(); it != prod.end(); it++)
	{
		if ((*it) != NULL) cout << (*it)->ProductID << tab << (*it)->ProductName << tab << (*it)->QuantityPerUnit << tab << (*it)->UnitPrice << tab << (*it)->UnitsInStock << tab << (*it)->UnitsOnDoor << endl;
		else cout << "No Registeration Found!" << endl;
	}
}
void Interface::ShowOrders(list<Order*>&ord)
{
	cout << "OrderID	OrderDate	RequiredDate	ShippedDate"
			"	ShipVia ShipName	ShipAddress"
			"	ShipCity	ShipRegion		ShipPostalCode	ShipCountry		Flag" << endl;
	list<Order*>::iterator it;
	string tab = "		";
	for (it = ord.begin(); it != ord.end(); it++)
	{
		if ((*it) != NULL) 
			cout << (*it)->OrderID << tab << (*it)->OrderDate.Day_Month_Year << tab << (*it)->RequiredDate.Day_Month_Year << tab << (*it)->ShippedDate.Day_Month_Year 
			<< tab << (*it)->ShipVia << tab << (*it)->ShipName << tab << (*it)->ShipAddress 
			<< tab << (*it)->ShipCity << tab << (*it)->ShipRegion << tab << (*it)->ShipCity << tab << (*it)->ShipRegion << tab << (*it)->ShipPostalCode 
			<< tab << (*it)->ShipCountry << tab << (*it)->Flag << endl;
		
		else cout << "No Registeration Found!" << endl;
	}
}
void Interface::ShowCategories(list<Category*>&cat)
{
	cout << "ID		Name	Description" << endl;
	list<Category*>::iterator it;
	string tab = "		";
	for (it = cat.begin(); it != cat.end(); it++)
	{
		if ((*it) != NULL) cout << (*it)->CatID << tab << (*it)->CategoryName << tab << (*it)->Description << endl;
		else cout << "No Registeration Found!" << endl;
	}
}
void Interface::ShowOrderDetailss(list<OrderDetails*>&ordDet)
{
	cout << "OrdDetID   Unit Price		Quantity	Discount" << endl;
	list<OrderDetails*>::iterator it;
	string tab = "		";
	for (it = ordDet.begin(); it != ordDet.end(); it++)
	{
		if ((*it) != NULL) cout << (*it)->OrdDetID << tab << (*it)->UnitPrice << tab << (*it)->Quantity <<  tab << (*it)->Discount << endl;
		else cout << "No Registeration Found!" << endl;
	}
}

//Entity Editing Screens
void Interface::EditUserScreen(User * Usr)
{
	int newID;
	cout << "Available ID: " << Usr->UserID << endl
		 << "Enter a New ID: ";
	cin >> newID;

	string newName;
	cout << "Available Name: " << Usr->Name << endl
		<< "Enter a New Name: ";
	cin >> newName;

	string newEmail;
	cout << "Available Email: " << Usr->Email << endl
		<< "Enter a New Email: ";
	cin >> newEmail;

	string newAddress;
	cout << "Available Address: " << Usr->Address << endl
		<< "Enter a New Address: ";
	cin >> newAddress;

	string newPhone;
	cout << "Available Phone: " << Usr->Phone << endl
		<< "Enter a New Phone: ";
	cin >> newPhone;

	string newPassword;
	cout << "Available Password: " << Usr->Password << endl
		<< "Enter a New Password: ";
	cin >> newPassword;

	Usr->UserID = newID;
	Usr->Name = newName;
	Usr->Password = newPassword;
	Usr->Email = newEmail;
	Usr->Address = newAddress;
	Usr->Phone = newPhone;
	Usr->Password = newPassword;

	operation->InsertUser(Usr);
	database->OrderAndUser.push_back(Usr->UserID);// Bir Order sadece tek bir User'a özgüdür.

	system("CLS");

	while (true)
	{
		cout << "The new user registered successfully." << endl
			<< "Follow the instructions below to edit relationships!" << endl << endl
			<< "0 - Main Operations Menu" << endl
			<< "1 - Insert Orders" << endl;
		
		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");
		switch (InputKey)
		{
		case 0:
			system("CLS");
			MainOperationsMenu();
			break;
		case 1:
			while (true)
			{
				cout << " ------ All Orders List ------" << endl;
				ShowOrders(database->Orders);

				cout << "---------------------" << endl;

				cout << " ------ Available Orders List ------" << endl;
				ShowOrders(Usr->Orders);

				cout << "Enter the Order ID that you would like to insert: ";
				int oID;
				cin >> oID;

				while (oID == 0) cin >> oID;

				Order * Ord = database->FindOrder(oID);
				if (Ord != NULL)
				{
					Usr->Orders.push_back(Ord);
					Ord->user = Usr;

					cout << "Inserted Successfully." << endl;
					_getch();
					system("CLS");
					break;
				}
				else cout << "You entered the wrong ID!" << endl;
			}
			break;
		}
	}
}
void Interface::EditCustomerScreen(Customer * Cus)
{
	int newID;
	cout << "Available ID: " << Cus->CustomerID << endl
		<< "Enter a New ID: ";
	cin >> newID;

	string newName;
	cout << "Available Company Name: " << Cus->CompanyName << endl
		<< "Enter a New Company Name: ";
	cin >> newName;

	string newEmail;
	cout << "Default Email: " << Cus->Email << endl
		<< "Enter a New Email: ";
	cin >> newEmail;

	string newConTitle;
	cout << "Available Contact Title: " << Cus->ContactTitle << endl
		<< "Enter a New Contact Title: ";
	cin >> newConTitle;

	string newAddress;
	cout << "Default Address: " << Cus->Address << endl
		<< "Enter a New Address: ";
	cin >> newAddress;
	
	string newCity;
	cout << "Available City: " << Cus->City << endl
		<< "Enter a New City: ";
	cin >> newCity;

	string newRegion;
	cout << "Available Region: " << Cus->Region << endl
		<< "Enter a New Region: ";
	cin >> newRegion;

	string newPostalCode;
	cout << "Available Postal Code: " << Cus->PostalCode << endl
		<< "Enter a New Postal Code: ";
	cin >> newPostalCode;

	string newCountry;
	cout << "Available Country: " << Cus->Country << endl
		<< "Enter a New Country: ";
	cin >> newCountry;

	string newPhone;
	cout << "Available Phone: " << Cus->Phone << endl
		<< "Enter a New Phone: ";
	cin >> newPhone;
	
	string newFax;
	cout << "Available Fax: " << Cus->Fax << endl
		<< "Enter a New Fax: ";
	cin >> newFax;

	string newFlag;
	cout << "Available Flag: " << Cus->Flag << endl
		<< "Enter a New Flag: ";
	cin >> newFlag;

	Cus->CustomerID = newID;
	Cus->CompanyName = newName;
	Cus->Email = newEmail;
	Cus->ContactTitle = newConTitle;
	Cus->Address = newAddress;
	Cus->City = newCity;
	Cus->Region = newRegion;
	Cus->PostalCode = newPostalCode;
	Cus->Country = newCountry;
	Cus->Phone = newPhone;
	Cus->Fax = newFax;
	Cus->Flag = newFlag;

	operation->InsertCustomer(Cus);
	database->OrderAndCustomer.push_back(Cus->CustomerID);// Bir Order sadece tek bir Customer'a özgüdür.

	system("CLS");

	while (true)
	{
		cout << "The new customer registered successfully." << endl
			<< "Follow the instructions below to edit relationships!" << endl << endl
			<< "0 - Main Operations Menu" << endl
			<< "1 - Insert Orders" << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");
		switch (InputKey)
		{
		case 0:
			system("CLS");
			MainOperationsMenu();
			break;
		case 1:
			while (true)
			{
				cout << " ------ All Orders List ------" << endl;
				ShowOrders(database->Orders);

				cout << "---------------------" << endl;

				cout << " ------ Available Orders List ------" << endl;
				ShowOrders(Cus->Orders);

				cout << "Enter the Order ID that you would like to insert: ";
				int oID;
				cin >> oID;

				while (oID == 0) cin >> oID;

				Order * Ord = database->FindOrder(oID);
				if (Ord != NULL)
				{
					Cus->Orders.push_back(Ord);
					Ord->customer = Cus;
					
					cout << "Inserted Successfully." << endl;
					_getch();
					system("CLS");
					break;
				}
				else cout << "You entered the wrong ID!" << endl;
			}
			break;
		}
	}
}
void Interface::EditProductScreen(Product * Prod)
{
	int newID;
	cout << "Available ID: " << Prod->ProductID << endl
		<< "Enter a New ID: ";
	cin >> newID;

	string newName;
	cout << "Available Name: " << Prod->ProductName << endl
		<< "Enter a New Name: ";
	cin >> newName;

	int newQPU;
	cout << "Available Quantity Per Unit Value: " << Prod->QuantityPerUnit << endl
		<< "Enter a New Quantity Per Unit Value: ";
	cin >> newQPU;

	float newUnitPrice;
	cout << "Available Unit Price Value: " << Prod->UnitPrice << endl
		<< "Enter a New Unit Price Value: ";
	cin >> newUnitPrice;

	int newUIS;
	cout << "Available Units In Stock Value: " << Prod->UnitsInStock << endl
		<< "Enter a New Units In Stock Value: ";
	cin >> newUIS;

	int newUOD;
	cout << "Available Units On Door Value: " << Prod->UnitsOnDoor << endl
		<< "Enter a New Units On Door Value: ";
	cin >> newUOD;

	Prod->ProductID = newID;
	Prod->ProductName = newName;
	Prod->QuantityPerUnit = newQPU;
	Prod->UnitPrice = newUnitPrice;
	Prod->UnitsInStock = newUIS;
	Prod->UnitsOnDoor = newUOD;

	operation->InsertProduct(Prod);
	database->OrderDetailsAndProduct.push_back(Prod->ProductID);// Bir OrderDetails sadece tek bir Product'a özgüdür.

	system("CLS");

	while (true)
	{
		cout << "The new product registered successfully." << endl
			<< "Follow the instructions below to edit relationships!" << endl << endl
			<< "0 - Main Operations Menu" << endl
			<< "1 - Insert Order Details" << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");
		switch (InputKey)
		{
		case 0:
			system("CLS");
			MainOperationsMenu();
			break;
		case 1:
			while (true)
			{
				cout << " ------ All Order Details List ------" << endl;
				ShowOrderDetailss(database->OrderDetailss);

				cout << "---------------------" << endl;

				cout << " ------ Available Order Details List ------" << endl;
				ShowOrderDetailss(Prod->orderdetailss);

				cout << "Enter the Order Details ID that you would like to insert: ";
				int ODID;
				cin >> ODID;

				while (ODID == 0) cin >> ODID;

				OrderDetails * OrdDet = database->FindOrderDetails(ODID);
				if (OrdDet != NULL)
				{
					Prod->orderdetailss.push_back(OrdDet);
					OrdDet->product = Prod;
					
					cout << "Inserted Successfully." << endl;
					_getch();
					system("CLS");
					break;
				}
				else cout << "You entered the wrong ID!" << endl;
			}
			break;
		}
	}
}
void Interface::EditOrderScreen(Order * Ord)
{
	int newID;
	cout << "Available ID: " << Ord->OrderID << endl
		<< "Enter a New ID: ";
	cin >> newID;

	string newODate;
	cout << "Available OrderDate: " << Ord->OrderDate.Day_Month_Year << endl
		<< "Enter a New OrderDate: ";
	cin >> newODate;
	
	string newRDate;
	cout << "Available RequiredDate: " << Ord->RequiredDate.Day_Month_Year << endl
		<< "Enter a New RequiredDate: ";
	cin >> newRDate;
	
	string newSDate;
	cout << "Available ShippedDate: " << Ord->ShippedDate.Day_Month_Year << endl
		<< "Enter a New ShippedDate: ";
	cin >> newSDate;
	
	string newSVia;
	cout << "Available ShipVia: " << Ord->ShipVia << endl
		<< "Enter a New ShipVia: ";
	cin >> newSVia;

	string newSName;
	cout << "Available ShipName: " << Ord->ShipName << endl
		<< "Enter a New ShipName: ";
	cin >> newSName;

	string newSAddress;
	cout << "Available ShipAddress: " << Ord->ShipAddress << endl
		<< "Enter a New ShipAddress: ";
	cin >> newSAddress;

	string newSCity;
	cout << "Available ShipCity: " << Ord->ShipCity << endl
		<< "Enter a New ShipCity: ";
	cin >> newSCity;

	string newSRegion;
	cout << "Available ShipRegion: " << Ord->ShipRegion << endl
		<< "Enter a New ShipRegion: ";
	cin >> newSRegion;

	int newSPosCode;
	cout << "Available ShipPostalCode: " << Ord->ShipPostalCode << endl
		<< "Enter a New ShipPostalCode: ";
	cin >> newSPosCode;

	string newSCountry;
	cout << "Available ShipCountry: " << Ord->ShipCountry << endl
		<< "Enter a New ShipCountry: ";
	cin >> newSCountry;

	string newFlag;
	cout << "Available Flag: " << Ord->Flag << endl
		<< "Enter a New Flag: ";
	cin >> newFlag;

	Ord->OrderID = newID;
	Ord->OrderDate.Day_Month_Year = newODate;
	Ord->RequiredDate.Day_Month_Year = newRDate;
	Ord->ShippedDate.Day_Month_Year = newSDate;
	Ord->ShipVia = newSVia;
	Ord->ShipName = newSName;
	Ord->ShipAddress = newSAddress;
	Ord->ShipCity = newSCity;
	Ord->ShipRegion = newSRegion;
	Ord->ShipPostalCode = newSPosCode;
	Ord->ShipCountry = newSCountry;
	Ord->Flag = newFlag;

	operation->InsertOrder(Ord);
	database->OrderdetailsAndOrder.push_back(Ord->OrderID);// Bir OrderDetails sadece tek bir Order'a özgüdür.

	system("CLS");

	while (true)
	{
		cout << "The new order registered successfully." << endl
			<< "Follow the instructions below to edit relationships!" << endl << endl
			<< "0 - Main Operations Menu" << endl
			<< "1 - Insert Order Details" << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");
		switch (InputKey)
		{
		case 0:
			system("CLS");
			MainOperationsMenu();
			break;
		case 1:
			while (true)
			{
				cout << " ------ All Order Details List ------" << endl;
				ShowOrderDetailss(database->OrderDetailss);

				cout << "---------------------" << endl;

				cout << " ------ Available Order Details List ------" << endl;
				ShowOrderDetailss(Ord->orderdetailss);

				cout << "Enter the Order Details ID that you would like to insert: ";
				int ODID;
				cin >> ODID;

				while (ODID == 0) cin >> ODID;

				OrderDetails * OrdDet = database->FindOrderDetails(ODID);
				if (OrdDet != NULL)
				{
					Ord->orderdetailss.push_back(OrdDet);
					OrdDet->order = Ord;
					
					cout << "Inserted Successfully." << endl;
					_getch();
					system("CLS");
					break;
				}
				else cout << "You entered the wrong ID!" << endl;
			}
			break;
		}
	}
}
void Interface::EditCategoryScreen(Category * Cat)
{
	int newID;
	cout << "Available ID: " << Cat->CatID << endl
		<< "Enter a New ID: ";
	cin >> newID;

	string newName;
	cout << "Available Name: " << Cat->CategoryName << endl
		<< "Enter a New Name: ";
	cin >> newName;

	string newDesc;
	cout << "Available Description: " << Cat->Description << endl
		<< "Enter a New Description: ";
	cin >> newDesc;

	Cat->CatID = newID;
	Cat->CategoryName = newName;
	Cat->Description = newDesc;

	operation->InsertCategory(Cat);
	database->ProductAndCategory.push_back(Cat->CatID);//Bir Product sadece tek bir Category'e özgüdür.
	
	system("CLS");

	while (true)
	{
		cout << "The new category registered successfully." << endl
			<< "Follow the instructions below to edit relationships!" << endl << endl
			<< "0 - Main Operations Menu" << endl
			<< "1 - Insert Products" << endl;

		int InputKey;
		cin >> InputKey;
		while (InputKey != 0 && InputKey != 1)	cin >> InputKey;
		system("CLS");

		switch (InputKey)
		{
		case 0:
			system("CLS");
			MainOperationsMenu();
			break;
		case 1:
			while (true)
			{
				cout << " ------ All Products List ------" << endl;
				ShowProducts(database->Products);

				cout << "---------------------" << endl;

				cout << " ------ Available Products List ------" << endl;
				ShowProducts(Cat->Products);

				cout << "Enter the Product ID that you would like to insert: ";
				int pID;
				cin >> pID;

				while (pID == 0) cin >> pID;

				Product * Prod = database->FindProduct(pID);
				if (Prod != NULL)
				{
					Cat->Products.push_back(Prod);
					Prod->category = Cat;
					
					cout << "Inserted Successfully." << endl;
					_getch();
					system("CLS");
					break;
				}
				else cout << "You entered the wrong ID!" << endl;
			}
			break;
		}
	}
}
void Interface::EditOrderDetailsScreen(OrderDetails * OrdDet)
{
	int newID;
	cout << "Available ID: " << OrdDet->OrdDetID << endl
		<< "Enter a New ID: ";
	cin >> newID;

	float newUnitPrice;
	cout << "Available Unit Price Value: " << OrdDet->UnitPrice << endl
		<< "Enter a New Unit Price Value: ";
	cin >> newUnitPrice;

	int newQuantity;
	cout << "Available Quantity Value: " << OrdDet->Quantity << endl
		<< "Enter a New Quantity Value: ";
	cin >> newQuantity;

	int newDiscount;
	cout << "Available Discount Value: " << OrdDet->Discount << endl
		<< "Enter a New Discount Value: ";
	cin >> newDiscount;

	OrdDet->OrdDetID = newID;
	OrdDet->UnitPrice = newUnitPrice;
	OrdDet->Quantity = newQuantity;
	OrdDet->Discount = newDiscount;

	operation->InsertOrderDetails(OrdDet);

	cout << endl << "The new order details registered successfully.";
	_getch();
}