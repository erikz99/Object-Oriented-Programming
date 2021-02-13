#include <string>
#include "Clothes.h"

Clothes::Clothes(std::string name, double price, std::string color, size_t size)
	: Product(name,price)
	, c_color(color)
	, c_size(size)
{}

void Clothes::print() const
{
	Product::print();
	std::cout << "Color: " << c_color << ", Size: " << c_size;
}

std::string Clothes::getColor() const
{
	return c_color;
}

size_t Clothes::getSize() const
{
	return c_size;
}
