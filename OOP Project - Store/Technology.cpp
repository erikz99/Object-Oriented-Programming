#include <iostream>
#include <string>
#include "Technology.h"

Technology::Technology(std::string name, double price, std::string maker,
	std::string cpu, std::string os, size_t ram, size_t memory, size_t year, double screen)
	: Product(name,price)
	, t_maker(maker)
	, t_cpu(cpu)
	, t_os(os)
	, t_ram(ram)
	, t_memory(memory)
	, t_year(year)
	, t_screen(screen)
{}

void Technology::print() const 
{
	Product::print();
	std::cout << "Maker: " << t_maker << ", CPU: " << t_cpu << ", OS: " << t_os << ", RAM: " << t_ram
		<< ", Memory: " << t_memory << ", Year: " << t_year << ", Screen: " << t_screen << " inches";
}

std::string Technology::getMaker() const
{
	return t_maker;
}

std::string Technology::getCpu() const
{
	return t_cpu;
}

std::string Technology::getOS() const
{
	return t_os;
}

size_t Technology::getRam() const
{
	return t_ram;
}

size_t Technology::getMemory() const
{
	return t_memory;
}

size_t Technology::getYear() const
{
	return t_year;
}

double Technology::getScreen() const
{
	return t_screen;
}