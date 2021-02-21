#include <cstring>
#include "JSONObject.hpp"
#include "JSON.h"

template <class T>
class JSONArray : public JSON {
private:
    JSON** array;
    int size;
    int capacity;

    T* search_value(const char* key) const;
    void resize();
public:
    JSONArray();
    JSONArray(const JSONArray& from);

    JSONArray& operator= (const JSONArray& from);

    virtual ~JSONArray();

    JSONObject<T> operator[] (const int& pos) const;
    void insertObject(const char* key, T value);
    void insertArray(const JSONArray<T>& from);

 
    T get_value(const char* key) const;

    int get_size() const;

    virtual JSON* copy() override final;
};

template <class T>
T* JSONArray<T>::search_value(const char* key) const
{
    for (int i = 0; i < this->size; i++)
    {
        if (typeid(*this->array[i]) == typeid(JSONObject<T>)) {
            JSONObject<T>* ptr = dynamic_cast<JSONObject<T>*>(this->array[i]);

            if (strcmp(key, ptr->get_key()) == 0)
            {
                return new T(ptr->get_value());
            }
        }
        else if (typeid(*this->array[i]) == typeid(JSONArray<T>)) {
            JSONArray<T>* ptr = dynamic_cast<JSONArray<T>*>(this->array[i]);

            T* value = ptr->search_value(key);
            if (value != nullptr) {
                return value;
            }
        }
    }
    return nullptr;
}

template <class T>
void JSONArray<T>::resize()
{
    this->capacity *= 2;
    JSON** new_array = new JSON*[this->capacity];

    for (int i = 0; i < this->size; i++)
    {
        new_array[i] = this->array[i]->copy();
    }

    delete[] this->array;
    this->array = new_array;
}
template <class T>
JSONArray<T>::JSONArray()
{
    this->array = new JSON*[1];
    this->size = 0;
    this->capacity = 1;
}

template <class T>
JSONArray<T>::JSONArray(const JSONArray& from)
{
    this->array = new JSON*[from.capacity];
    this->size = from.size;
    this->capacity = from.capacity;

    for (int i = 0; i < this->size; i++)
    {
        this->array[i] = from.array[i];
    }
}

template <class T>
JSONArray<T>& JSONArray<T>::operator= (const JSONArray& from)
{
    if (this != &from)
    {
        delete[] this->array;

        this->array = new JSONObject<T>[from.capacity];
        this->size = from.size;
        this->capacity = from.capacity;

        for (int i = 0; i < this->size; i++)
        {
            this->array[i] = from.array[i]->copy();
        }
    }
    return *this;
}

template <class T>
JSONArray<T>::~JSONArray<T>()
{
    for (size_t i = 0; i < size; i++) {
        delete this->array[i];
    }

    delete[] this->array;
}

template <class T>
JSONObject<T> JSONArray<T>::operator[] (const int& pos) const
{
    return this->array[pos];
}

template <class T>
void JSONArray<T>::insertObject(const char* key, T value)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }
    JSONObject<T>* temp = new JSONObject<T>();
    temp->set_key(key);
    temp->set_value(value);

    this->array[this->size] = temp;
    this->size++;
}

template <class T>
void JSONArray<T>::insertArray(const JSONArray<T>& from)
{
    if (this->size == this->capacity)
    {
        this->resize();
    }
    JSONArray<T>* temp = new JSONArray<T>(from);
    this->array[this->size] = temp;
    this->size++;
}

template <class T>
T JSONArray<T>::get_value(const char* key) const
{
    T* value = search_value(key);
    if (value != nullptr) {
        T returnValue = *value;
        delete value;
        return returnValue;
    }
    std::cout << "key not found";
    return T();
}

template <class T>
int JSONArray<T>::get_size() const
{
    return this->size;
}

template <class T>
JSON* JSONArray<T>::copy()
{
    return new JSONArray(*this);
}