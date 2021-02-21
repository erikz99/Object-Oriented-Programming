#include "File.h"

File::File(const string& name, const string& extension, size_t size_in_mb)
	: Item(name)
	, f_extension(extension)
	, f_size_in_mb(size_in_mb)
{}

size_t File::getSize() const
{
	return f_size_in_mb;
}

string File::getExtension() const
{
	return f_extension;
}

Item* File::clone()
{
	return new File(*this);
}