#include <iostream>
#include <algorithm>
#include "Shop.h"
#include <string.h>
#include "User.h"

Shop::Shop() : numOfProducts(0), numOfUsers(0), activeUsers(0)
{}

Shop& Shop::instance() 
{
	static Shop inst;
	return inst;
}

void Shop::showProducts(Order order)
{
	switch (order) {
		case Order::LEAST_RECENT: {
			sort(products.begin(), products.end(), [](const Product* p1, const Product* p2) { return p1->getTime() > p2->getTime();});
			break;
		}
		case Order::MOST_RECENT: {
			sort(products.begin(), products.end(), [](const Product* p1, const Product* p2) { return p1->getTime() < p2->getTime();});
			break;
		}
		case Order::PRICE_DESC: {
			sort(products.begin(), products.end(), [](const Product* p1, const Product* p2) { return p1->getPrice() > p2->getPrice(); });
			break;
		}
		default:
			sort(products.begin(), products.end(), [](const Product* p1, const Product* p2) { return p1->getPrice() < p2->getPrice();});
			
	}
	std::cout << "[\n";
	for (size_t i = 0; i < products.size(); i++) {
		products[i]->print();
		std::cout << ", Available: " << quantities[products[i]->getName()] << "\n\n";
	}
	std::cout << "]\n";
}

void Shop::addUser(const User& usr)
{
	if (findUser(usr.getUsername()) == nullptr) {
		
		users.push_back(usr);
		numOfUsers++;
	}
}

void Shop::addProduct(Product* pr, size_t num)
{
	std::string name = pr->getName();
	Product* foundProduct = findProduct(name);
	if (foundProduct == nullptr) {
		products.push_back(pr);
		quantities[name] = num;
		numOfProducts++;
	}
	else {
		quantities[name]+= num;
	}
}

void Shop::login(std::string name, std::string password)
{
	User* usr = findUser(name);
	if (usr){
		if (usr->checkPassword(password)) {
			activeUsers++;
		}
	}
}

void Shop::logout(std::string name, std::string password)
{
	User* usr = findUser(name);
	if (usr) 
		if (usr->checkPassword(password)) 
			activeUsers--;
}

void Shop::buyProduct(std::string username, std::string productName, size_t num)
{
	User* user = findUser(username);
	Product* product = findProduct(productName);

	if (user == nullptr || product == nullptr)
		return;

	if (quantities[productName] < num)
		num = quantities[productName];

	if (user->getMoney() < num * product->getPrice())
		return;

	user->addToCart(product,num);
	user->spendMoney(num * product->getPrice());

	if (quantities[productName] == num)
		findProduct(product->getName(), Operation::REMOVE);
	else
		quantities[productName] -= num;

}

void Shop::returnProduct(std::string username, std::string productName)
{
	User* user = findUser(username);
	Product* product = findProduct(productName);

	if (user == nullptr)
		return;

	size_t num = user->removeFromCart(productName);
	user->addMoney(num * product->getPrice());

	if (product) 
		quantities[productName] += num;
}

void Shop::showCart(std::string username)
{
	User* user = findUser(username);
	if (user != nullptr) {
		user->showCart();
	}
}

void Shop::showUsers() const
{
	std::cout << "[\n";
	for (size_t i = 0; i < users.size(); i++) {
		users[i].print();
	}
	std::cout << "]\n";
}

size_t Shop::getActiveUsers() const
{
	return activeUsers;
}

User* Shop::findUser(std::string username)
{
	for (size_t i = 0; i < users.size(); i++)
		if (users[i].getUsername() == username)
			return &users[i];
	return nullptr;
}

Product* Shop::findProduct(std::string productName, Operation op)
{
	for (size_t i = 0; i<products.size(); i++) {
		if (products[i]->getName() == productName) {
			switch (op) {
				case Operation::FIND: {
					return products[i];
				}
				case Operation::REMOVE: {
					products.erase(products.begin()+i);
				}
			}
		}
	}
	return nullptr;
}