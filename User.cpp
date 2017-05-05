#include "User.h"

User::User(int userId, string name, string email, string address, string phone, string password)
{
	UserID = userId;
	Name = name;
	Email = email;
	Address = address;
	Phone = phone;
	Password = password;
}

User::~User()
{
}
