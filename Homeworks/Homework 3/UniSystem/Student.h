#pragma once
#include <string>
#include "Course.h"
#include "Grade.h"
#include <vector>
using namespace std;

class Student
{
public:
	Student(string name = "", size_t facn = 0);

private:
	string s_name;
	size_t s_facn;
	vector <Course> s_courses;
	vector <Grade> s_grades;
};