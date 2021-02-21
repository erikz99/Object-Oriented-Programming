#include <iostream>
#include <typeinfo>
#include "Folder.h"

Folder::Folder(const string& name) 
	: Item(name)
{}

Folder::Folder(const Folder& folder)
	: Item(folder)
{
	items.resize(folder.items.size());
	for (size_t i = 0; i < folder.items.size(); i++) {
		items.push_back(folder.items[i]->clone());
	}
}

Folder& Folder::operator=(const Folder& folder)
{
	if (this != &folder) {
		for (int i = 0; i < items.size(); i++) {
			delete items[i];
		}

		Item::operator=(folder);
		items.resize(folder.items.size());
		for (size_t i = 0; i < folder.items.size(); i++) {
			items.push_back(folder.items[i]->clone());
		}
	}
	return *this;
}

Folder::~Folder()
{
	for (int i = 0; i < items.size(); i++) {
		delete items[i];
	}
}

File Folder::find(string filename)
{
	File* file = search(filename);
	if (file != nullptr) {
		return *file;
	}
	std::cout << "Not found" << std::endl;
	return {};
}

void Folder::add(Item* item)
{
	items.push_back(item);
}

Item* Folder::clone()
{
	return new Folder(*this);
}

File* Folder::search(string filename)
{
	for (size_t i=0 ; i<items.size(); i++)
	{
		File* filePtr = dynamic_cast<File*>(items[i]);

		if (filePtr) {
			if (items[i]->getName() == filename) {
				return filePtr;
			}
		}
		
		Folder* folderPtr = dynamic_cast<Folder*>(items[i]);

		if (folderPtr) {
			File* file = folderPtr->search(filename);
			if (file != nullptr) {
				return file;
			}
		}
		
	}
	return nullptr;
}