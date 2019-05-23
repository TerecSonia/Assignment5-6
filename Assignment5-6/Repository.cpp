#include "Repository.h"
#include <assert.h>

int Repository::findByNameAndAge(const string & name, const int & age)
{
	for (int i = 0; i < this->dogs.getSize(); i++)
	{
		if (this->dogs[i].getName() == name && this->dogs[i].getAge() == age)
			return i;
	}
	return -1;
}

bool Repository::addDog(const Dog& dog)
{
	if (findByNameAndAge(dog.getName(), dog.getAge()) == -1)
	{
		///this->dogs.add(dog);
		///this->dogs = this->getDogs() + dog;
		this->dogs = dog + this->getDogs();
		return true;
	}
	return false;
}


bool Repository::deleteDog(const string& name, const int& age)
{
	int index = findByNameAndAge(name, age);
	if (index != -1)
	{
		this->dogs.deleteElem(index);
		return true;
	}
	return false;

}

bool Repository::updateDog(const string & name, const int & age, const Dog & dog)
{
	int index = findByNameAndAge(name, age);
	if (index != -1)
	{
		this->dogs.update(index, dog);
		return true;
	}
	return false;
}

