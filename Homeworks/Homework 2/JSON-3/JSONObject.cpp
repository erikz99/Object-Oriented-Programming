#include <cstring>
#include "JSONObject.h"

JSONObject::JSONObject() : key(nullptr), value(0) {};

JSONObject::JSONObject(const char* k, int v) : value(v)
{
	int sizeOfKey = strlen(k);
	key = new char[sizeOfKey + 1];
	strcpy(key, k);
}

JSONObject::JSONObject(const JSONObject& json)
{
	this->value = json.value;
	int sizeOfKey = strlen(json.key);
	key = new char[sizeOfKey + 1];
	strcpy(key, json.key);
}

JSONObject& JSONObject::operator=(const JSONObject& json)
{
	if (this != &json)
	{
		delete[]key;
		this->value = json.value;
		int sizeOfKey = strlen(json.key);
		key = new char[sizeOfKey + 1];
		strcpy(key, json.key);
	}
	return *this;
}

JSONObject::~JSONObject()
{
	delete[]key;
}

char* JSONObject::getKey()
{
	return key;
}

int JSONObject::getValue()
{
	return value;
}
