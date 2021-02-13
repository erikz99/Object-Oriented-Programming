#include <iostream>
#include <string>
#include "Laptop.h"

Laptop::Laptop(std::string name, double price, std::string maker, std::string cpu, std::string os
	, size_t ram, size_t memory, size_t year, double screen, std::string RAMType
	, std::string graphicsCard)
	: Technology(name,price,maker,cpu,os,ram,memory,year,screen)
	, l_RAMType(RAMType)
	, l_graphicsCard(graphicsCard)
{}

void Laptop::print() const 
{
	std::cout << "Laptop: " << std::endl;
	Technology::print();
	std::cout << std::endl;
	std::cout << "RAM type: " << l_RAMType << "Graphics card: " << l_graphicsCard;
}

std::string Laptop::getGraphicsCard() const
{
	return l_graphicsCard;
}

std::string Laptop::getRAMType() const
{
	return l_RAMType;
}