#pragma once
#include "Rectangle.h"

class SVG
{
private:
	Rectangle* rectangles;
	int size;
	int capacity;

public:
	SVG();
	~SVG();
	SVG(const SVG&);
	SVG& operator=(const SVG&);
	void addRectangle(const Rectangle&);
	void createRectangle(const Point&, const Point&);
	int getPosition() const;
};