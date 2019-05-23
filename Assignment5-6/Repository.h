#pragma once
#include "Dog.h"
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector<Dog> dogs;
public:
	///Default constructor
	Repository() {}

	/*Checks if there exists a dog in the list with the given name and age
	IN:name-string,age-int
	OUT:i-int (the poz if it exists,0 otherwise)
	*/
	int findByNameAndAge(const string& name, const int& age);

	/*Adds a dog in the repo if it doesn't exist
	IN:dog-Dog
	OUT:true-bool (the dog was added)
		false-bool (the dog already exists)
	*/
	bool addDog(const Dog& dog);

	/*Deletes a dog from the repo if it exists
	IN:name-string,age-int
	OUT:true-bool (the dog was deleted)
		false-bool (the dog doesn't exist)*/
	bool deleteDog(const string& name, const int& age);

	/*Updates a dog from the repo if it exists
	IN:name-string,age-int
	OUT:true-bool (the dog was updated)
		false-bool (the dog doesn't exist)*/
	bool updateDog(const string& name, const int& age, const Dog& dog);

	/*Returns the dynamic vector of the dogs from the repo
	IN:-
	OUT:this->dogs-DynamicVector*/
	DynamicVector<Dog> getDogs() const { return this->dogs; }


};