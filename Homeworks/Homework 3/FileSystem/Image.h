#pragma once
#include <string>
#include "File.h"
using namespace std;

class Image : public File
{
public:
	Image(const string& name = "", const string& extension = "", size_t size_in_mb = 0, const string device = "", double resolution = 0);
	
private:
	string i_device;
	double i_resolution;

};