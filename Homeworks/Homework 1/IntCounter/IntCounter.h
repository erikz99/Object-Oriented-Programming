#pragma once

class IntCounter
{
private:
	int* intPtr;
	int* count;

public:
	IntCounter();
	IntCounter(int*);
	~IntCounter();
	IntCounter(const IntCounter&);
	IntCounter& operator=(const IntCounter&);
	int get_count() const;
	int get_value() const;
};