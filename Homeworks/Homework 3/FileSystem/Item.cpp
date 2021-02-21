#include <time.h>
#include "Item.h"

Item::Item(const string& name)
	: i_name(name)
	, i_date_created(time(NULL))
{}

string Item::getName() const
{
	return i_name;
}

Item* Item::clone()
{
	return new Item(*this);
}