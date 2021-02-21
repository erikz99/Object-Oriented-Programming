#pragma once
#include "Folder.h"
#include "File.h"

class FileSystem
{
public:
	FileSystem(const Folder& folder);
	File search(string fileName);

private:
	Folder main;
};