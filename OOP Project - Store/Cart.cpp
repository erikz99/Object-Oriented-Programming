#include <iostream>
#include "Cart.h"
#include "Product.h"
#include "Shop.h"

Cart::Cart() : totalPrice(0)
{}

void Cart::addProduct(Product *prod, size_t num) 
{
	std::string name = prod->getName();
	for (size_t i = 0; i < products.size(); i++) {
		if (name == products[i]->getName()) {
			quantities[name]+=num;
			return;
		}
	}

	products.push_back(prod);
	quantities[name] = num;
	totalPrice += num * prod->getPrice();
}

size_t Cart::removeProduct(std::string product_name)
{
	for (auto i = products.begin(); i<products.end(); i++) {
		std::string p_name = (*i)->getName();
		if (product_name == p_name) {
			size_t num = quantities[product_name];
			products.erase(i);
			return num;
		}
	}
	return 0;
}

size_t Cart::getNum(std::string product_name) {
	for (size_t i = 0; i < products.size(); i++) {
		if (products[i]->getName() == product_name) {
			return quantities[product_name];
		}
	}
	return 0;
}

void Cart::print() 
{
	std::cout << "[\n";
	for (size_t i = 0; i < products.size(); i++) {
		products[i]->print();
		std::string name = products[i]->getName();
		std::cout << ", Quantity: " << quantities[name] << "\n";
	}
	std::cout << "]" << std::endl;
}