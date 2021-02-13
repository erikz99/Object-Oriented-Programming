#pragma once
#include <string>
#include "Product.h"

class Clothes : public Product
{
public: 
	Clothes(std::string name = "", double price = 0, std::string color = "", size_t size = 0);
	
	virtual void print() const override;
	std::string getColor() const;
	size_t getSize() const;

private:
	std::string c_color;
	size_t c_size;
};