#include <string>
#include "Shoes.h"

Shoes::Shoes(std::string name, double price, std::string color, size_t size, std::string sole, std::string type)
	: Clothes(name, price, color, size)
	, s_sole(sole)
	, s_type(type)
{}

void Shoes::print() const
{
	std::cout << "Shoes: ";
	std::cout << std::endl;
	Clothes::print();
	std::cout << std::endl;
	std::cout << "Sole: " << s_sole << ", Type: " << s_type;
}

std::string Shoes::getSole() const
{
	return s_sole;
}

std::string Shoes::getType() const
{
	return s_type;
}
