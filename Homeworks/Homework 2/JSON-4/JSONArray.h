#pragma once
#include <fstream>
#include "JSONObject.h"

class JSONArray
{
private:
	JSONObject* arr;
	static const int DEFAULT_CAPACITY;
	int size;
	int capacity;

public:
	JSONArray(int capacity = 0);
	JSONArray(const JSONArray& json);
	JSONArray& operator=(const JSONArray& json);
	~JSONArray();

	void reserve(int newCapacity);
	void add(const char* key, int value);
	void remove(const char* key);
	int getValue(const char* key);
};