#include <iostream>
#include <string>
#include "User.h"
using namespace std;

User::User(std::string username, std::string password, std::string email, double money) :
	u_username(username), u_password(password), u_email(email), u_money(money)
{}

void User::addToCart(Product* pr, unsigned int num)
{
	cart.addProduct(pr,num);
}

void User::showCart() 
{
	cart.print();
}

void User::addMoney(double money)
{
	u_money += money;
}

void User::spendMoney(double money)
{
	u_money -= money;
}

bool User::checkPassword(std::string password)
{
	return u_password == password;
}

std::string User::getUsername() const
{
	return u_username;
}

size_t User::removeFromCart(std::string product_name)
{
	return cart.removeProduct(product_name);
}

size_t User::findNum(std::string product_name) {
	return cart.getNum(product_name);
}

double User::getMoney() const
{
	return u_money;
}

void User::print() const
{
	std::cout << "Username: " << u_username << ", Email: " << u_email << ", Money: " << u_money << std::endl;
}

