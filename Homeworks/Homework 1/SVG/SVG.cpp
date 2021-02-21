#include "SVG.h"

SVG::SVG()
{
	this->rectangles = new Rectangle[10];
	this->size = 0;
	this->capacity = 10;
}

SVG::~SVG() {
	delete[] rectangles;
}

SVG::SVG(const SVG& svg) {
	size = svg.size;
	capacity = svg.capacity;

	rectangles = new Rectangle[capacity];
	for (int i = 0; i < size; i++) {
		rectangles[i] = svg.rectangles[i];
	}
}

SVG& SVG::operator=(const SVG& svg) {
	if (this != &svg) {
		delete [] rectangles;
		size = svg.size;
		capacity = svg.capacity;

		rectangles = new Rectangle[capacity];
		for (int i = 0; i < size; i++) {
			rectangles[i] = svg.rectangles[i];
		}
	}
	return *this;
}

void SVG::addRectangle(const Rectangle& rectangle)
{
	if (size == capacity)
	{
		delete[]this->rectangles;
		this->rectangles = new Rectangle[capacity * 2];
		capacity *= 2;
	}

	rectangles[size] = rectangle;
	size++;
}

void SVG::createRectangle(const Point& p1, const Point& p2)
{
	Rectangle rectangle(p1, p2);
	if (size == capacity)
	{
		delete[]this->rectangles;
		this->rectangles = new Rectangle[capacity * 2];
		capacity *= 2;
	}

	rectangles[size] = rectangle;
	size++;
}

int SVG::getPosition() const
{
	if (size == 0) return -3456;
	int maxArea = -1;
	int index = -1;

	for (int i = 0; i < size; i++)
	{
		if (rectangles[i].getArea() > maxArea)
		{
			maxArea = rectangles[i].getArea();
			index = i;
		}
	}
	return index;
}