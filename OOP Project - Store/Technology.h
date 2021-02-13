#pragma once
#include <string>
#include "Product.h"

class Technology : public Product
{
public:
	Technology(std::string name = "", double price = 0, std::string maker = "", std::string cpu = "", std::string os = ""
		, size_t ram = 0, size_t memory = 0, size_t year = 0, double screen = 0);

	virtual void print() const override;
	std::string getMaker() const;
	std::string getCpu() const;
	std::string getOS() const;
	size_t getRam() const;
	size_t getMemory() const;
	size_t getYear() const;
	double getScreen() const;

private:
	std::string t_maker;
	std::string t_cpu;
	std::string t_os;
	size_t t_ram;
	size_t t_memory;
	size_t t_year;
	double t_screen;
};