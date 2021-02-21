#pragma once
#include <string>
#include <time.h>
#include "Item.h"
using namespace std;

class File : public Item
{
public:
	File(const string& name = "", const string& extension = "", size_t size_in_mb = 0);
	string getExtension() const;
	size_t getSize() const;

	virtual Item* clone() override final;

protected:
	string f_extension;
	size_t f_size_in_mb;
};