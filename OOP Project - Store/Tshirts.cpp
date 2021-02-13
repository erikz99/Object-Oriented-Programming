#include <string>
#include "Tshirts.h"

Tshirts::Tshirts(std::string name, double price, std::string color, size_t size, std::string brand
	, std::string materials)
	: Clothes(name, price, color, size)
	, t_brand(brand)
	, t_materials(materials)
{}

void Tshirts::print() const
{
	std::cout << "Tshirt: " << std::endl;
	Clothes::print();
	std::cout << std::endl;
	std::cout << "Brand: " << t_brand << ", Materials: " << t_materials;
}

std::string Tshirts::getBrand()
{
	return t_brand;
}

std::string Tshirts::getMaterials()
{
	return t_materials;
}