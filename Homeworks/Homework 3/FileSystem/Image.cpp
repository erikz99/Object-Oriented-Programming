#include "Image.h"

Image::Image(const string& name, const string& extension, size_t size_in_mb, const string device, double resolution)
	: File(name,((extension == ".jpg" || extension == ".png") ? extension : ".jpg"),size_in_mb)
	, i_device(device)
	, i_resolution(resolution)
{}
