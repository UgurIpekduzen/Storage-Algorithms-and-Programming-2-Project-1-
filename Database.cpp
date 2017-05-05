#include "Database.h"

Database::Database()
{
}

Database::~Database()
{
}

void Database::Build()
{
	Build("User.txt", "Customer.txt", "Product.txt", "Order.txt","Category.txt","OrderDetails.txt");
}//Bir alttaki fonksiyonu girilen parametre deðerlerine göre çalýþtýrýr.
void Database::Build(string UsrSrcFile, string CustSrcFile, string ProdSrcFile, string OrdSrcFile,string CatSrcFile,string OrdDetSrcFile)
{
	ReadUsers(UsrSrcFile);
	ReadCustomers(CustSrcFile);
	ReadCategories(CatSrcFile);
	ReadProducts(ProdSrcFile);
	ReadOrders(OrdSrcFile);
	ReadOrderDetails(OrdDetSrcFile);

	RelateOrderAndUser();
	RelateOrderAndCustomer();
	RelateProductAndCategory();
	RelateOrderDetailsAndProduct();
    RelateOrderDetailsAndOrder();
}//Parametre olarak girilen isimdeki .txt dosyalarýndaki verileri okuyup kaydedilmiþ iliþkilerini kurar.

bool Database::Save()
{
	bool isSaved = Save("User.txt", "Customer.txt", "Product.txt", "Order.txt", "Category.txt", "OrderDetails.txt");
	return isSaved;
}//Bir alttaki fonksiyonu girilen parametre deðerlerine göre çalýþtýrýr.
bool Database::Save(string UsrSrcFile, string CustSrcFile, string ProdSrcFile, string OrdSrcFile, string CatSrcFile, string OrdDetSrcFile)
{
	bool isSavedUser = SaveUser(UsrSrcFile);
	bool isSavedCustomer = SaveCustomer(CustSrcFile);
	bool isSavedProduct = SaveProduct(ProdSrcFile);
	bool isSavedOrder = SaveOrder(OrdSrcFile);
	bool isSavedCategory = SaveCategory(CatSrcFile);
	bool isSavedOrderDetails = SaveOrderDetails(OrdDetSrcFile);

	bool result = isSavedUser && isSavedCustomer && isSavedProduct && isSavedOrder && isSavedCategory && isSavedOrderDetails;
	return result;
}//Parametre olarak girilen isimdeki .txt dosyalarýna databasedeki liste pointerlardaki verilerin kaydedilip edilmediðini kontrol eder.

//Find Methods
/*
- Fonksiyon içerisine parametre olarak giren ID 'ye kayýtlý nesneyi bulup return deðeri olarak döndürürler. 
*/
User * Database:: FindUser(int ID)
{
	User * ThatUser = NULL;
	list<User*>::iterator it;
	for (it = Users.begin(); it != Users.end(); it++)
	{
		if ((*it)->UserID == ID)
		{
			ThatUser = *it;
			break;
		}
	}
	return ThatUser;
}
Customer * Database:: FindCustomer(int ID)
{
	Customer * ThatCustomer = NULL;
	list<Customer*>::iterator it;
	for (it = Customers.begin(); it != Customers.end(); it++)
	{
		if ((*it)->CustomerID == ID) 
		{
			ThatCustomer = *it;
			break;
		}
	}
	return ThatCustomer;
	
}
Order * Database:: FindOrder(int ID)
{
	Order * ThatOrder = NULL;
	list<Order*>::iterator it;
	for (it = Orders.begin(); it != Orders.end(); it++)
	{
		if ((*it)->OrderID == ID) 
		{
			ThatOrder = *it;
			break;
		}
	}
	return ThatOrder;
}
Category * Database:: FindCategory(int ID)
{
	Category * ThatCategory = NULL;
	list<Category*>::iterator it;
	for (it = Categories.begin(); it != Categories.end(); it++)
	{
		if ((*it)->CatID == ID)
		{
			ThatCategory = *it;
			break;
		}
	}
	return ThatCategory;
}
Product * Database:: FindProduct(int ID)
{
	Product * ThatProduct = NULL;
	list<Product*>::iterator it;
	for (it = Products.begin(); it != Products.end(); it++)
	{
		if ((*it)->ProductID == ID)
		{
			ThatProduct = *it;
			break;
		}
	}
	return ThatProduct;
}
OrderDetails * Database:: FindOrderDetails(int ID)
{
	OrderDetails * ThoseOrderDetails = NULL;
	list<OrderDetails*>::iterator it;
	for (it = OrderDetailss.begin(); it != OrderDetailss.end(); it++)
	{
		if ((*it)->OrdDetID == ID)
		{
			ThoseOrderDetails = *it;
			break;
		}
	}
	return ThoseOrderDetails;
}

// Data Installation Methods
/*
- Oluþturulmuþ .txt dosyasý içindeki listelenmiþ verileri dosyanýn sonuna kadar
belirtilen sýrada okuyup ilgili classlarýn Database sýnýfý içerisindeki listelerine yerleþtirirler.
*/
void Database::ReadUsers(string UsrSrcFile)
{
	ifstream File;
	File.open(UsrSrcFile);

	if (File.is_open())
	{
		int userID;
		char row[1000];
		File.getline(row, 1000);//.txt dosyasýndaki baþlýðý okur.
		string name, email, address, phone, password;
		while (!File.eof())
		{   
			File >> userID >> name >> email >> address >> phone >> password;
			OrderAndUser.push_back(userID); // Bir Order sadece tek bir User'a özgüdür.
			Users.push_back(new User(userID, name, email, address, phone, password));
		}
		File.close();
	}

}
void Database::ReadCustomers(string CustSrcFile)
{
	ifstream File;
	File.open(CustSrcFile);

	if (File.is_open())
	{
		char row[1000];
		File.getline(row, 1000);//.txt dosyasýndaki baþlýðý okur.
		int cusID;
		string comName, email, conTitle, address,
			city, region, posCode, country,
			phone, fax, flag;
		while (!File.eof())
		{

			File >> cusID >> comName >> email >> conTitle >> address >> city >> region >> posCode >> country >> phone >> fax >> flag;
			Customers.push_back(new Customer(cusID, comName, email, conTitle,
				address, city, region, posCode,
				country, phone, fax, flag));
			OrderAndCustomer.push_back(cusID);// Bir Order sadece tek bir Customer'a özgüdür.
		}
		File.close();
	}
}
void Database::ReadProducts(string ProdSrcFile)
{
	ifstream File;
	File.open(ProdSrcFile);

	if (File.is_open())
	{
		char row[1000];
		File.getline(row, 1000);//.txt dosyasýndaki baþlýðý okur.
		int pID, catID, QPU, UIS, UOD;
		float uPrice;
		string pName;
		Category * tempCat;
		Product * tempProd;
		while (!File.eof())
		{
			File >> pID >> pName >> catID >> QPU >> uPrice >> UIS >> UOD;
			
			Products.push_back(new Product(pID, pName, QPU, uPrice, UIS, UOD));
			OrderDetailsAndProduct.push_back(pID);// Bir OrderDetails sadece tek bir Product'a özgüdür.

			tempCat= FindCategory(catID);
			tempProd = FindProduct(pID);
			tempProd->category = tempCat; //Ýliþkiyi kuracak nesne pointerýnýn içerisine dosyada kayýtlý ayný dönüþ tipli nesneyi yerleþtir. 
		}
		File.close();
	}
}
void Database::ReadOrders(string OrdSrcFile)
{
	ifstream File;
	File.open(OrdSrcFile);

	if (File.is_open())
	{
		char row[1000];
		File.getline(row, 1000);//.txt dosyasýndaki baþlýðý okur.
		int oID, sCode, cusID, usrID;
		string oDate, rDate, sDate, sVia, sName, sAddress, sCity, sRegion, sCountry, flag;
		User * tempUsr;
		Customer * tempCus;
		Order * tempOrd;
		while (!File.eof())
		{
			File >> oID >> oDate >> rDate >> sDate >> sVia >> sName >>
					sAddress >> sCity >> sRegion >>
						sCode >> sCountry >> flag >> usrID >> cusID;
			
			Orders.push_back(new Order(oID, oDate, rDate, sDate, sVia, sName, sAddress, sCity, sRegion, sCode, sCountry, flag));
			OrderdetailsAndOrder.push_back(oID);// Bir OrderDetails sadece tek bir Order'a özgüdür.

			tempOrd = FindOrder(oID);
			tempCus = FindCustomer(cusID);
			tempUsr = FindUser(usrID);
			//Ýliþkiyi kuracak nesne pointerýnýn içerisine dosyada kayýtlý ayný dönüþ tipli nesneyi yerleþtir.
			tempOrd->customer = tempCus;
			tempOrd->user = tempUsr;
		}
		File.close();
	}
}
void Database::ReadCategories(string CatSrcFile)
{
	ifstream File;
	File.open(CatSrcFile);

	if (File.is_open())
	{
		char row[1000];
		File.getline(row, 1000);//.txt dosyasýndaki baþlýðý okur.
		int catID;
		string catName, desc;
		while (!File.eof())
		{
			File >> catID >> catName >> desc;
			Categories.push_back(new Category( catID, catName, desc));
			ProductAndCategory.push_back(catID);//Bir Product sadece tek bir Category'e özgüdür.
		}
		File.close();
	}
}
void Database::ReadOrderDetails(string OrdDetSrcFile)
{
	ifstream File;
	File.open(OrdDetSrcFile);

	if (File.is_open())
	{
		char row[1000];
		File.getline(row, 1000);//.txt dosyasýndaki baþlýðý okur.
		float uPrice;
		int OrddetID, quantity, discount, prodID, ordID;
		OrderDetails * tempOD;
		Product * tempProd;
		Order * tempOrd;
		while (!File.eof())
		{
			File >> OrddetID >> uPrice >> quantity >> discount >> prodID >> ordID;
			OrderDetailss.push_back(new OrderDetails(OrddetID, uPrice, quantity, discount));
			
			tempOD = FindOrderDetails(OrddetID);
			tempProd = FindProduct(prodID);
			tempOrd = FindOrder(ordID);
			//Ýliþkiyi kuracak nesne pointerýnýn içerisine dosyada kayýtlý ayný dönüþ tipli nesneyi yerleþtir.
			tempOD->order = tempOrd;
			tempOD->product = tempProd;
		}
		File.close();
	}
}

//Relate Methods
/*
- Dosyadan okunan veriyi liste elemaný biçiminde,içinde liste pointer tutan nesneye ekleyerek
iki sýnýf arasýndaki bire çok iliþkiyi kurarlar.
*/
void Database::RelateOrderAndUser()
{
	list<int>::iterator i;
	for (i = OrderAndUser.begin(); i != OrderAndUser.end(); i++)
	{
		User * Usr = FindUser(*i);
		if (Usr != NULL) 
		{
			list<Order*>::iterator j;
			for (j = Orders.begin(); j != Orders.end(); j++)
			{
				if ((*j)->user != NULL)
				{
					if ((*j)->user->UserID == Usr->UserID)
					{
						Usr->Orders.push_back(*j);
					}
				}
				
			}
		}
	}
}
void Database::RelateOrderAndCustomer()
{
	list<int>::iterator i;
	for (i = OrderAndCustomer.begin(); i != OrderAndCustomer.end(); i++)
	{
		Customer * Cus = FindCustomer(*i);
		if (Cus != NULL)
		{
			list<Order*>::iterator j;
			for (j = Orders.begin(); j != Orders.end(); j++)
			{
				if((*j)->customer !=NULL)
				{
					if ((*j)->customer->CustomerID == Cus->CustomerID)
					{
						Cus->Orders.push_back(*j);
					}
				}
				
			}
		}
	}
}
void Database::RelateProductAndCategory()
{
	list<int>::iterator i;
	for (i = ProductAndCategory.begin(); i != ProductAndCategory.end(); i++)
	{
		Category * Cat = FindCategory(*i);
		if (Cat != NULL) 
		{
			list<Product*>::iterator j;
			for (j = Products.begin(); j != Products.end(); j++)
			{
				if ((*j)->category != NULL)
				{
					if ((*j)->category->CatID == Cat->CatID)
					{
						Cat->Products.push_back(*j);
					}
				}
				
			}
		}
	}
}
void Database::RelateOrderDetailsAndProduct()
{
	list<int>::iterator i;
	for (i = OrderDetailsAndProduct.begin(); i != OrderDetailsAndProduct.end(); i++)
	{
		Product * Prod = FindProduct(*i);
		if (Prod != NULL) 
		{
			list<OrderDetails*>::iterator j;
			for (j = OrderDetailss.begin(); j != OrderDetailss.end(); j++)
			{
				if((*j)->product !=NULL)
				{ 
					if ((*j)->product->ProductID == Prod->ProductID)
					{
						Prod->orderdetailss.push_back(*j);
					}
				}
			}
		}
	}
}
void Database::RelateOrderDetailsAndOrder()
{
	list<int>::iterator i;
	for (i = OrderdetailsAndOrder.begin(); i != OrderdetailsAndOrder.end(); i++)
	{
		Order * Ord = FindOrder(*i);
		if (Ord!= NULL) 
		{
			list<OrderDetails*>::iterator j;
			for (j = OrderDetailss.begin(); j != OrderDetailss.end(); j++)
			{
				if ((*j)->order != NULL)
				{
					if ((*j)->order->OrderID == Ord->OrderID)
					{
						Ord->orderdetailss.push_back(*j);
					}
				}
			}
		}
	}
}

//Remove Relationship Methods
/*
- Ýliþkilendirilmiþ nesnelerin ID lerini kayýtlý olduðu int listeden silip iki class arasýndaki iliþkiyi koparýrlar.
*/
void Database::RemoveRelationshipOrderandUser(User * Usr)
{
	OrderAndUser.erase(find(OrderAndUser.begin(), OrderAndUser.end(), Usr->UserID));
}
void Database::RemoveRelationshipOrderandCustomer(Customer * Cus)
{
	OrderAndCustomer.erase(find(OrderAndCustomer.begin(), OrderAndCustomer.end(), Cus->CustomerID));
}
void Database::RemoveRelationshipOrderDetailsAndProduct(Product * Prod)
{
	OrderDetailsAndProduct.erase(find(OrderDetailsAndProduct.begin(), OrderDetailsAndProduct.end(), Prod->ProductID));
}
void Database::RemoveRelationshipOrderDetailsAndOrder(Order * Ord)
{
	OrderdetailsAndOrder.erase(find(OrderdetailsAndOrder.begin(), OrderdetailsAndOrder.end(), Ord->OrderID));
}
void Database::RemoveRelationshipProductandCategory(Category * Cat)
{
	ProductAndCategory.erase(find(ProductAndCategory.begin(), ProductAndCategory.end(), Cat->CatID));
}

//Save Methods
/*
- Database içerisinde,verilerini tuttuðu sýnýflarýn dönüþ tipindeki liste pointerlarýn içindeki verileri
belirtilen sýrada ilgili dosyaya kaydederler. 
*/
bool Database::SaveUser(string UsrSrcFile)
{
	ofstream File;
	File.open(UsrSrcFile);
	if (File.is_open())
	{
		File << "UserID		Name	Email	Address		Phone	Password";//.txt dosyasýna sýrasýyla eklenmiþ veri isimleri(Baþlýk) 
		string tab = "	";
		list<User*>::iterator i;
		for (i = Users.begin(); i != Users.end(); i++)
		{
			int userID = (*i)->UserID;
			string name = (*i)->Name;
			string email = (*i)->Email;
			string address = (*i)->Address;
			string phone = (*i)->Phone;
			string password = (*i)->Password;

			File << endl << userID << tab << name << tab << email << tab << address << tab << phone << tab << password;
		}
		File.close();
		return true;
	}
	else return false;
}
bool Database::SaveCustomer(string CustSrcFile)
{
	ofstream File;
	File.open(CustSrcFile);
	if (File.is_open())
	{
		File << "CustomerID	CompanyName	Email	ContactTitle	Address	 City	Region  PostalCode  Country  Phone	Fax	 Flag";//.txt dosyasýna sýrasýyla eklenmiþ veri isimleri(Baþlýk) 
		string tab = "	";
		list<Customer*>::iterator i;
		for (i = Customers.begin(); i != Customers.end(); i++)
		{
			int customerID = (*i)->CustomerID;
			string comName = (*i)->CompanyName;
			string email = (*i)->Email;
			string conTitle = (*i)->ContactTitle;
			string address = (*i)->Address;
			string city = (*i)->City;
			string region = (*i)->Region;
			string posCode = (*i)->PostalCode;
			string country = (*i)->Country;
			string phone = (*i)->Phone;
			string fax = (*i)->Fax;
			string flag = (*i)->Flag;
			
			File << endl << customerID << tab << comName << tab << email 
				<< tab << conTitle << tab << address << tab << city << tab 
				<< region << tab << posCode << tab << country << tab 
				<< phone << tab << fax << tab << flag;
		}
		File.close();
		return true;
	}
	else return false;
}
bool Database::SaveProduct(string ProdSrcFile)
{
	ofstream File;
	File.open(ProdSrcFile);
	if (File.is_open())
	{
		File << "ProductID		ProductName 	Category(ID)	QuantityPerUnit		UnitPrice	UnitsInStock	UnitsOnDoor  ";//.txt dosyasýna sýrasýyla eklenmiþ veri isimleri(Baþlýk) 
		string tab = "	";
		list<Product*>::iterator i;
		for (i = Products.begin(); i != Products.end(); i++)
		{ 
			int productID = (*i)->ProductID;
			string prodName = (*i)->ProductName;
			int QPU = (*i)->QuantityPerUnit;
			float unitPrice = (*i)->UnitPrice;
			int UIS = (*i)->UnitsInStock;
			int UOD = (*i)->UnitsOnDoor;
			int catID;

			if ((*i)->category == NULL) catID = -1; //Eðer hiçbir iliþkisi yoksa,dosya içindeki (ID) kýsmýna iliþkisi yok anlamýnda -1 yaz.
			else catID = (*i)->category->CatID; //Eðer iliþkisi varsa,dosya içindeki (ID) kýsmýna iliþkisi yok anlamýnda nesnenin ID sini yaz.
			
			File << endl << productID << tab << prodName << tab << catID << tab << QPU << tab << unitPrice << tab << UIS << tab << UOD;
		}
		File.close();
		return true;
	}
	else return false;
}
bool Database::SaveOrder(string OrdSrcFile)
{
	ofstream File;
	File.open(OrdSrcFile);
	if (File.is_open())
	{
		File << "OrderID	OrderDate	RequiredDate	ShippedDate"
			"	ShipVia ShipName	ShipAddress"
			"	ShipCity	ShipRegion		ShipPostalCode	ShipCountry		Flag	User(ID)	Customer(ID)";//.txt dosyasýna sýrasýyla eklenmiþ veri isimleri(Baþlýk) 
		string tab = "	";
		list<Order*>::iterator i;
		for (i = Orders.begin(); i != Orders.end(); i++)
		{
			int oID = (*i)->OrderID;
			string oDate = (*i)->OrderDate.Day_Month_Year;
			string rDate = (*i)->RequiredDate.Day_Month_Year;
			string sDate = (*i)->ShippedDate.Day_Month_Year;
			string sVia = (*i)->ShipVia;
			string sName = (*i)->ShipName;
			string sAddress = (*i)->ShipAddress;
			string sCity = (*i)->ShipCity;
			string sRegion = (*i)->ShipRegion;
			int sPosCode = (*i)->ShipPostalCode;
			string sCountry = (*i)->ShipCountry;
			string flag = (*i)->Flag;
			int cusID, usrID;
			/*
			Eðer hiçbir iliþkisi yoksa,dosya içindeki (ID) kýsmýna iliþkisi yok anlamýnda -1 yaz.
			Eðer iliþkisi varsa,dosya içindeki (ID) kýsmýna iliþkisi yok anlamýnda nesnenin ID sini yaz.
			*/
			if ((*i)->customer == NULL) cusID = -1;
			else cusID = (*i)->customer->CustomerID;
			
			if ((*i)->user == NULL) usrID = -1;
			else usrID = (*i)->user->UserID;

			File << endl << oID << tab << oDate << tab << rDate 
				<< tab << sDate << tab << sVia << tab << sName 
				<< tab << sAddress << tab << sCity << tab << sRegion 
				<< tab << sPosCode << tab << sCountry << tab << flag << tab << usrID << tab << cusID;
		}
		File.close();
		return true;
	}
	else return false;
}
bool Database::SaveCategory(string CatSrcFile)
{
	ofstream File;
	File.open(CatSrcFile);
	if (File.is_open())
	{
		File << "CatID		CategoryName	Description";//.txt dosyasýna sýrasýyla eklenmiþ veri isimleri(Baþlýk) 
		string tab = "	";
		list<Category*>::iterator i;
		for (i = Categories.begin(); i != Categories.end(); i++)
		{
			int catID = (*i)->CatID;
			string catName = (*i)->CategoryName;
			string desc = (*i)->Description;

			File << endl << catID << tab << catName << tab << desc;
		}
		File.close();
		return true;
	}
	else return false;
}
bool Database::SaveOrderDetails(string OrdDetSrcFile)
{
	ofstream File;
	File.open(OrdDetSrcFile);
	if (File.is_open())
	{
		File << "ID		UnitPrice		Quantity	Discount	Product(ID)		Order(ID)";//.txt dosyasýna sýrasýyla eklenmiþ veri isimleri(Baþlýk) 
		string tab = "	";
		list<OrderDetails*>::iterator i;
		for (i = OrderDetailss.begin(); i != OrderDetailss.end(); i++)
		{
			int ODID = (*i)->OrdDetID;
			float unitPrice = (*i)->UnitPrice;
			int quantity = (*i)->Quantity;
			int discount = (*i)->Discount;
			int prodID, ordID;
			/*
			Eðer hiçbir iliþkisi yoksa,dosya içindeki (ID) kýsmýna iliþkisi yok anlamýnda -1 yaz.
			Eðer iliþkisi varsa,dosya içindeki (ID) kýsmýna iliþkisi yok anlamýnda nesnenin ID sini yaz.
			*/
			if ((*i)->product == NULL) prodID = -1;
			else prodID = (*i)->product->ProductID;
			
			if ((*i)->order == NULL) ordID = -1;
			else ordID = (*i)->order->OrderID;
			
			File << endl << ODID << tab << unitPrice << tab << quantity << tab << discount << tab << prodID << tab << ordID;
		}
		File.close();
		return true;
	}
	else return false;
}


