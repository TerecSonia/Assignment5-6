#include "DynamicVector.h"
///trebuie mutate in .h
template <typename T>
DynamicVector<T>::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v) {
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}

template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template <typename T>
T & DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename T>
DynamicVector<T> & DynamicVector<T>::operator + (const T & e)
{
	if (this->capacity == this->size)
		this->resize();
	this->elems[this->size++] = e;
	return *this;
}

template <typename T>
DynamicVector<T> operator+(const T& e, const DynamicVector<T> vector)
{
	DynamicVector<T> v;
	v = vector;
	v.add(e);
	return v;
}

template <typename T>
void DynamicVector<T>::add(const T& d)
{
	if (this->size == this->capacity)
		this->resize();

	this->elems[this->size++] = d;
}

template <typename T>
void DynamicVector<T>::deleteElem(const int & poz)
{
	for (int i = poz; i < this->size - 1; i++)
	{
		this->elems[i] = this->elems[i + 1];
	}
	this->size--;
}

template <typename T>
void DynamicVector<T>::update(const int & poz, const T & d)
{
	this->elems[poz] = d;
}

template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	T* newElems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		newElems[i] = this->elems[i];

	delete[] this->elems;
	this->elems = newElems;
}

template <typename T>
int DynamicVector<T>::getSize() const { return this->size; }

template <typename T>
T* DynamicVector<T>::getAllElems() const { return this->elems; }
