#pragma once
#include <string>
using namespace std;

class Teacher
{
	Teacher(string name = "", string title = "");

private:
	string t_name;
	string t_title;
	vector <Course> t_courses;
};