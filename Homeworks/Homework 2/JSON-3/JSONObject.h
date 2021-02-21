#pragma once
#include <fstream>

class JSONObject
{
private:
	char* key;
	int value;

public:
	JSONObject();
	JSONObject(const char* k, int v);
	JSONObject(const JSONObject& json);
	JSONObject& operator=(const JSONObject& json);
	~JSONObject();
	char* getKey();
	int getValue();
};