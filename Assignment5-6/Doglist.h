#pragma once
#include "Dog.h"
#include "DynamicVector.h"

class Doglist
{
private:
	DynamicVector<Dog> dogs;
	int currentPos;
public:
	///Default constructor
	Doglist();

	/*Adds a dog to the adoption list
	IN:d-Dog
	OUT:-
	*/
	void add(const Dog& d);

	/*Returns all the dogs from the adoption list
	IN:-
	OUT: this->dogs-DynamicVector<Dog>
	*/
	DynamicVector<Dog> getDogs() const { return this->dogs; }

	/*Returns the current dog
	IN:-
	OUT:Dog
	*/
	Dog getCurrentDog();
};
