#pragma once
#include "Point.h"

class Rectangle
{
public:
	Rectangle();
	Rectangle(const Point&, const Point&);
	double getArea() const;

private:
	Point p1, p2;
};