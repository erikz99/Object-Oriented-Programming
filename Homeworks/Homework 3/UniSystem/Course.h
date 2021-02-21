#pragma once
#include <string>
#include "Teacher.h"
#include "Student.h"
using namespace std;

class Course
{
public:
	Course(string name = "", string type = "", size_t code = 0, Teacher teacher = {});

private:
	string c_name;
	string c_type;
	size_t c_code;
	Teacher c_teacher;
	vector <Student> c_stduents;
};