#include "Phone.h"

Phone::Phone(std::string name, double price, std::string maker, std::string cpu, std::string os
	, size_t ram, size_t memory, size_t year, double screen, std::string camera
	, std::string color, double weight)
	: Technology(name,price,maker,cpu,os,ram,memory,year,screen)
	, p_camera(camera)
	, p_color(color)
	, p_weight(weight)
{}

void Phone::print() const
{
	std::cout << "Phone" << std::endl;
	Technology::print();
	std::cout << std::endl;
	std::cout << "Camera: " << getCamera() << ", Color: " << getColor() << ", Weight: " << getWeight() << " g";
}

std::string Phone::getCamera() const
{
	return p_camera;
}

std::string Phone::getColor() const
{
	return p_color;
}

double Phone::getWeight() const
{
	return p_weight;
}