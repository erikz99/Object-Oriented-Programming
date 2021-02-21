#include "MyString.h"
#include <string.h>
#include <iostream>

MyString::MyString()
{
	this->string = nullptr;
}

MyString::MyString(const char* string)
{
	int stringLen = strlen(string);
	this->string = new char[stringLen + 1];
	strcpy(this->string, string);
}


MyString::MyString(const MyString& myString)
{
	int myStringLen = strlen(myString.string);
	this->string = new char[myStringLen + 1];
	strcpy(this->string, myString.string);
}

MyString::~MyString()
{
	delete[]this->string;
}

void MyString::print() const
{
	std::cout << this->string;
	std::cout << '\n';
}

void MyString::append(const char addition)
{
	int stringLen = strlen(this->string);
	char* ptr = this->string;
	this->string = new char[stringLen + 2];
	for (int i = 0; i < stringLen; i++)
	{
		this->string[i] = ptr[i];
	}
	this->string[stringLen] = addition;
	this->string[stringLen+1] = '\0';
	delete[]ptr;
}

MyString& MyString::operator=(const MyString& myString)
{
	delete[]this->string;
	int stringLen = strlen(myString.string);
	this->string = new char[stringLen + 1];
	strcpy(this->string, myString.string);
	return *this;
}

bool MyString::operator==(const MyString& myString)
{
	int stringLen = strlen(this->string);
	int myStringLen = strlen(myString.string);
	if (stringLen != myStringLen)
	{
		return false;
	}
	else
	{
		int i = 0;
		while (i != stringLen)
		{
			if (this->string[i] != myString.string[i])
			{
				return false;
			}
			i++;
		}
		return true;
	}
}

bool MyString::operator!=(const MyString& obj)
{
	return !(*this == obj);
}

bool MyString::operator<(const MyString& myString)
{
	int thisStringLen = strlen(this->string);
	int strLen = strlen(myString.string);
	int i = 0; 
	while (i != thisStringLen && i != strLen && this->string[i]== myString.string[i])
	{
		i++;
	}
	if (i == thisStringLen && i == strLen)
	{
		return false;
	}
	else if (i == thisStringLen)
	{
		return true;
	}
	else if (i == strLen)
	{
		return false;
	}
	else
	{
		if (this->string[i] < myString.string[i]) return true;
		return false;
	}
}

bool MyString::operator>(const MyString& obj)
{
	return ((!(*this < obj)) && (!(*this == obj)));
}