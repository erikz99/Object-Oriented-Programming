#include "MyString.h"
#include <iostream>
#include <cstring>

MyString::MyString()
{
    content = new char[1];
    content[0] = '\0';
}

MyString::MyString(const char* input)
{
    int len = strlen(input);
    this->content = new char[len + 1];

    strcpy(this->content, input);
    this->content[len] = '\0';
}
MyString::MyString(const MyString& from)
{
    int len = strlen(from.content);
    this->content = new char[len + 1];
    strcpy(this->content, from.content);
    this->content[len] = '\0';
}

MyString& MyString::operator=(const MyString& from)
{
    if (this != &from)
    {
        delete[] content;

        int len = strlen(from.content);
        this->content = new char[len + 1];
        strcpy(this->content, from.content);
        this->content[len] = '\0';
    }
    return *this;
}

MyString::~MyString()
{
    delete[] this->content;
}

void MyString::append(char to_append)
{
    int len = strlen(this->content);
    char* new_content = new char[len + 2];
    strcpy(new_content, this->content);
    new_content[len] = to_append;
    new_content[len + 1] = '\0';
    delete[] this->content;
    this->content = new_content;
}

void MyString::print()
{
    std::cout << this->content << std::endl;
}

void MyString::setContent(const char* input)
{
    if (input != nullptr)
    {
        delete[]this->content;
        this->content = new char[strlen(input) + 1];
        strcpy(this->content, input);
    }
}

std::ostream& operator<<(std::ostream& out, const MyString& string)
{
    out << string.content;
    return out;
}

std::istream& operator>>(std::istream& in, MyString& string)
{
    char buffer[1024];
    in >> buffer;
    string.setContent(buffer);
    return in;
}
