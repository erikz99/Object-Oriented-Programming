#pragma once
#include <iostream>

class MyString {
private:
    char* content;
public:
    MyString();
    MyString(const char* input);

    MyString(const MyString& from);

    MyString& operator=(const MyString& from);

    ~MyString();

    void append(char to_append);
    void print();
    void setContent(const char* input);
    friend std::ostream& operator<<(std::ostream& out, const MyString& string);
    friend std::istream& operator>>(std::istream& in, MyString& string);
};
