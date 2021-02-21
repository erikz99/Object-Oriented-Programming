#include <iostream>
#include <cstring>
#include <fstream>
#include "JSONArray.h"

const int JSONArray::DEFAULT_CAPACITY = 10;

JSONArray::JSONArray(int capacity)
{
	this->capacity = 0;
	int max = capacity > DEFAULT_CAPACITY ? capacity : DEFAULT_CAPACITY;
	reserve(max);
}

JSONArray::JSONArray(const JSONArray& json)
{
	size = json.size;
	capacity = json.capacity;

	arr = new JSONObject[capacity];
	for (int i = 0; i < size; i++)
		arr[i] = json.arr[i];
}

JSONArray& JSONArray::operator=(const JSONArray& json)
{
	if (this != &json)
	{
		delete[]arr;
		size = json.size;
		capacity = json.capacity;

		arr = new JSONObject[capacity];
		for (int i = 0; i < size; i++)
			arr[i] = json.arr[i];
	}
	return *this;
}
JSONArray::~JSONArray()
{
	delete[]arr;
}

void JSONArray::reserve(int newCapacity)
{
	if (capacity >= newCapacity)
		return;

	if (capacity == 0)
		capacity = DEFAULT_CAPACITY;

	while (capacity < newCapacity)
		capacity *= 2;

	JSONObject* newArr = new JSONObject[capacity];

	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];

	delete[]arr;
	arr = newArr;
}

void JSONArray::add(const char* key, int value)
{
	if (size <= capacity)
		reserve(capacity * 2);

	arr[size++] = JSONObject(key, value);
}

void JSONArray::remove(const char* key)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].getKey(), key) == 0)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		std::cout << "Wrong key!" << std::endl;
		return;
	}

	for (int i = index; i < size-1; i++)
	{
		JSONObject temp(arr[i]);
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
	size--;
}

int JSONArray::getValue(const char* key)
{
	int index = -1;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(arr[i].getKey(), key) == 0)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		std::cout << "Wrong key!" << std::endl;
		return 4214125;
	}

	return arr[index].getValue();
}

void JSONArray::writeToFile(const char* fileName)
{
	std::ofstream out;
	out.open(fileName, std::ios::app);
	if (out)
	{;
		for (int i = 0; i < size; i++)
		{
			out << "{" << arr[i].getKey() << ", " << arr[i].getValue() << "}" << "\n";
		}
	}
	out.close();
}