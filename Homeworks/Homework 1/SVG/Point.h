#pragma once

class Point
{
public:
	Point();
	Point(double, double);
	double getX() const;
	double getY() const;

	double x, y;
};