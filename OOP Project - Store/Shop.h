#include <vector>
#include "User.h"
#include "Product.h"
#pragma once

class Shop
{
public:
	enum class Order {
		PRICE_ASC,
		PRICE_DESC,
		MOST_RECENT,
		LEAST_RECENT,
		YEAR_ASC,
		YEAR_DESC,
	};

	enum class Operation {
		FIND,
		REMOVE
	};

	Shop(const Shop& shop) = delete;
	Shop& operator=(const Shop& shop) = delete;

	static Shop& instance();

	void showProducts(Order order = Order::PRICE_ASC);
	void addUser(const User&);
	void addProduct(Product* pr, size_t num);
	void login(std::string username, std::string password);
	void logout(std::string username, std::string password);
	void buyProduct(std::string username, std::string productName, size_t num=1);
	void returnProduct(std::string username, std::string productName);
	void showCart(std::string username);
	void showUsers() const;
	size_t getActiveUsers() const;

private:
	Shop();

	User* findUser(std::string username);
	Product* findProduct(std::string productName, Operation op = Operation::FIND);

	std::vector <User> users;
	std::vector <Product*> products;
	std::unordered_map <std::string, size_t> quantities;
	size_t numOfUsers;
	size_t numOfProducts;
	size_t activeUsers;
};