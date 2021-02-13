#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Product.h"

class Cart
{
public:
	Cart();

	void addProduct(Product* pr, size_t num=1);
	size_t removeProduct(std::string product_name);
	size_t getNum(std::string product_name);
	void print();

private:
	std::vector <Product*> products;
	std::unordered_map <std::string, size_t> quantities;
	double totalPrice;
};