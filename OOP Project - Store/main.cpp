#include <iostream>
#include "Shop.h"
#include "Phone.h"
#include "Laptop.h"
#include "Shoes.h"
#include "Tshirts.h"
#include <thread> 
#include <chrono> 

int main()
{
	User a("Erik", "password1", "erik@abv.bg", 10000);
	User b("Plamen", "password2", "plamen@abv.bg", 15000);
	User c("Kristian", "password3", "kristian@abv.bg", 19000);
	User d("Nikolai", "password4", "nikolai@abv.bg", 20000);
	Shop::instance().addUser(a);
	Shop::instance().addUser(b);
	Shop::instance().addUser(c);
	Shop::instance().addUser(d);
	Shop::instance().showUsers();
	std::cout << std::endl;
	Laptop l1("Acer Aspire 5", 1500);
	Phone p1("Iphone x", 2000);
	Shoes s1("Adidas mercurial", 150);
	Tshirts t1("Big boss", 30);
	Shop::instance().addProduct(&l1,5);
	Shop::instance().addProduct(&p1,6);
	Shop::instance().addProduct(&s1,2);
	Shop::instance().addProduct(&t1,10);
	Shop::instance().showProducts(Shop::Order::PRICE_ASC);
	std::cout << std::endl;
	Shop::instance().buyProduct("Nikolai", "Iphone x",2);
	Shop::instance().showUsers();
	std::cout << std::endl;
	Shop::instance().showProducts(Shop::Order::PRICE_DESC);
	std::cout << std::endl;
	Shop::instance().showCart("Nikolai");
}
