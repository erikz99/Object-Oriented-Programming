#pragma once
#include <string>
#include "File.h"
using namespace std;

class Music : public File
{
public:
	Music(const string& name = "", const string& extension = "", 
		size_t size_in_mb = 0, const string& singer = ""
		, const string& mName = "", size_t year = 0);

private:
	string m_singer;
	string m_name;
	size_t m_year;
};
