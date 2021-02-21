#pragma once
#include <cstring>
#include <iostream>
#include "JSON.h"

template <class T>
class JSONObject : public JSON {
private:
    char* key;
    T value;
public:
    JSONObject();
    JSONObject(const JSONObject& from);
    JSONObject<T>& operator=(const JSONObject& from);
    virtual ~JSONObject();

    void set_key(const char* key);
    void set_value(T value);

    const char* get_key() const;
    T get_value() const;

    virtual JSON* copy() override final;
};

template <class T>
JSONObject<T>::JSONObject()
{
    this->key = new char[1];
    this->key[0] = '\0';
    this->value = T(); 
}

template <class T>
JSONObject<T>::JSONObject(const JSONObject& from)
{
    this->key = new char[strlen(from.key) + 1];
    strcpy(this->key, from.key);
    this->value = from.value;
}

template <class T>
JSONObject<T>& JSONObject<T>::operator=(const JSONObject& from)
{
    if (this != &from)
    {
        this->set_key(from.key);
        this->set_value(from.value);
    }
    return *this;
}

template <class T>
JSONObject<T>::~JSONObject()
{
    delete[] this->key;
}

template <class T>
void JSONObject<T>::set_key(const char* key)
{
    delete[] this->key;
    int len = strlen(key);
    this->key = new char[len + 1];
    strcpy(this->key, key);
    this->key[len] = '\0';
}

template <class T>
void JSONObject<T>::set_value(T value)
{
    this->value = value;
}

template <class T>
const char* JSONObject<T>::get_key() const
{
    return this->key;
}

template <class T>
T JSONObject<T>::get_value() const
{
    return this->value;
}

template <class T>
JSON* JSONObject<T>::copy()
{
    return new JSONObject<T>(*this);
}
