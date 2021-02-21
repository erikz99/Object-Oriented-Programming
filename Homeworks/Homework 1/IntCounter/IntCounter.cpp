#include "IntCounter.h"
using namespace std;

IntCounter::IntCounter()
{
	this->intPtr = nullptr;
	this->count = new int(0);
}

IntCounter::IntCounter(int* intPtr)
{
	this->intPtr = intPtr;
	this->count = new int(1);
}

IntCounter::~IntCounter()
{
	(*(this->count))--;
	if (*(this->count) == 0)
	{
		delete this->count;
		delete this->intPtr;
	}
}

IntCounter::IntCounter(const IntCounter& intCounter)
{
	this->intPtr = intCounter.intPtr;
	this->count = intCounter.count;
	(*(this->count))++;
}

IntCounter& IntCounter::operator=(const IntCounter& intCounter)
{
	if (this != &intCounter) {
		this->intPtr = intCounter.intPtr;
		this->count = intCounter.count;
		(*(this->count))++;
		return *this;
	}
}


int IntCounter::get_count() const
{
	return *(this->count);
}

int IntCounter::get_value() const
{
	return *(this->intPtr);
}