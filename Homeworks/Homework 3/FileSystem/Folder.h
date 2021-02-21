#pragma once
#include <vector>
#include <string>
#include "Item.h"
#include "File.h"
using namespace std;

class Folder : public Item
{
public:
	Folder(const string& name = "");
	Folder(const Folder& folder);
	Folder& operator=(const Folder& folder);
	~Folder();

	File find(string filename);
	void add(Item* item);
	virtual Item* clone() override final;
private:
	File* search(string filename);
	vector <Item*> items;
};