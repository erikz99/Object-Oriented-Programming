#pragma once
#include <iostream>
#include <string>
#include "Cart.h"

class User
{
public:
	User(std::string username = "noname", std::string password= "nopassword", std::string email = "noemail", double money=0);

	void addToCart(Product* pr, unsigned int num=1);
	void showCart();
	void addMoney(double money);
	void spendMoney(double money);
	bool checkPassword(std::string password);
	std::string getUsername() const;
	size_t removeFromCart(std::string product_name);
	size_t findNum(std::string product_name);
	double getMoney() const;

	void print() const;

private:
	void copy(const User& usr);

	double u_money;
	std::string u_username;
	std::string u_password;
	std::string u_email;
	Cart cart;
};