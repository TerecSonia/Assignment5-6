#pragma once

template <typename T>

class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;
public:
	///Default constructor
	DynamicVector(int capacity = 10);

	///Copy contructor
	DynamicVector(const DynamicVector<T>& v);

	///Destructor
	~DynamicVector();

	///Operator =
	DynamicVector<T>& operator=(const DynamicVector<T>& v);

	///Operator []
	T& operator[](int pos);

	///Operator +
	DynamicVector<T>& operator + (const T& e);

	/*Add an element to the dynamic vector
	IN:d-TElement
	OUT:-
	*/
	void add(const T& d);

	/*Deletes an element of the dynamic vector from a given position
	IN:poz-int
	OUT:-
	*/
	void deleteElem(const int& poz);

	/*Updates an element of the dynamic vector from a given position
	IN:poz-int
	OUT:-
	*/
	void update(const int& poz, const T& d);

	/*Returns the size of the dynamic vector
	IN:-
	OUT:this->size-int
	*/
	int getSize() const;

	/*Returns the elements of the dynamic vector
	IN:-
	OUT:this->elems-TElement
	*/
	T* getAllElems() const;

private:
	/*Resizes the capacity of the dynamic vector
	IN:factor=2-double
	OUT:-
	*/
	void resize(double factor = 2);
};


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

template <typename T>
DynamicVector<T> operator+(const T& e, const DynamicVector<T> vector);

