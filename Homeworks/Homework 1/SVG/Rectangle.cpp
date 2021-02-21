#include "Rectangle.h"

Rectangle::Rectangle()
{
	this->p1 = Point(0, 0);
	this->p2 = Point(0, 0);
}

Rectangle::Rectangle(const Point &p1, const Point &p2)
{
	this->p1 = p1;
	this->p2 = p2;
}

double Rectangle::getArea() const
{
	double side1 = p1.getX() > p2.getX() ? p1.getX() - p2.getX() : p2.getX() - p1.getX();
	double side2 = p1.getY() > p2.getY() ? p1.getY() - p2.getY() : p2.getY() - p1.getY();
	return side1 * side2;
}