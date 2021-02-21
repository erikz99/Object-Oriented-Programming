#include "FileSystem.h"

FileSystem::FileSystem(const Folder& folder)
	: main(folder)
{}

File FileSystem::search(string fileName)
{
	return main.find(fileName);
}