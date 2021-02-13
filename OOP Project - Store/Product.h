#pragma once
#include <iostream>
#include <ctime>
#include <string>

class Product
{
public:
	Product(std::string name = "" , double price = 0);

	std::string getName() const;
	double getPrice() const;
	time_t getTime() const;
	virtual void print() const;

private:

	std::string p_name;
	double p_price;
	time_t time_created;
};