#pragma once
#include <string>
#include "Technology.h"

class Laptop : public Technology
{
public:
	Laptop(std::string name = "", double price=0, std::string maker = "", std::string cpu = "", std::string os = ""
		, size_t ram = 0 , size_t memory = 0, size_t year = 0, double screen = 0, std::string RAMTtype = ""
		, std::string graphicsCard = "");

	virtual void print() const override final;
	std::string getGraphicsCard() const;
	std::string getRAMType() const;

private:
	std::string l_RAMType;
	std::string l_graphicsCard;
};