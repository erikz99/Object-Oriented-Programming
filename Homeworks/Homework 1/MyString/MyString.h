#pragma once

class MyString
{

public:
	MyString();
	MyString(const char*);
	MyString(const MyString&);
	~MyString();

	void print() const;
	void append(const char);
	MyString& operator=(const MyString&);
	bool operator==(const MyString&);
	bool operator!=(const MyString&);
	bool operator<(const MyString&);
	bool operator>(const MyString&);

private:
	char* string;
};