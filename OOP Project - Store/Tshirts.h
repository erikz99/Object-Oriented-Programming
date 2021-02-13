#include <string>
#include "Clothes.h"

class Tshirts : public Clothes
{
public:
	Tshirts(std::string name = "", double price = 0, std::string color = "", size_t size = 0, std::string brand = ""
		, std::string materials = "");

	virtual void print() const override final;
	std::string getBrand();
	std::string getMaterials();

private:
	std::string t_brand;
	std::string t_materials;

};