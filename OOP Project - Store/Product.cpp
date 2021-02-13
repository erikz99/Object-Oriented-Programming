#include <string>
#include "Product.h"


Product::Product(std::string name, double price) 
	: time_created(time(nullptr))
	, p_price(price)
	, p_name(name)
{}

std::string Product::getName() const
{
	return p_name;
}

double Product::getPrice() const
{
	return p_price;
}

time_t Product::getTime() const
{
	return time_created;
}

void Product::print() const 
{
	std::cout << "Name: " << p_name << ", Price: " << p_price << ", Created: " << ctime(&time_created);
}
