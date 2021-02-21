#pragma once
#include <string>
using namespace std;

class Item
{
public:
	Item(const string& name = "");
	string getName() const;
	virtual Item* clone();

protected:
	string i_name;
	time_t i_date_created;
};