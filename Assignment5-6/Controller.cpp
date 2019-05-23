#include "Controller.h"
#include <assert.h>

Controller::Controller(const Repository & repo, const Doglist & doglist)
{
	this->repo = repo;
	this->doglist = doglist;
}

bool Controller::addDogCtrl(const string& breed, const string& name, const int& age, const string& photograph)
{
	Dog dog{ breed,name,age,photograph };

	return this->repo.addDog(dog);
}

bool Controller::deleteDogCtrl(const string & name, const int & age)
{
	return this->repo.deleteDog(name, age);
}

bool Controller::updateDogCtrl(const string & name, const int & age, const Dog & dog)
{
	return this->repo.updateDog(name, age, dog);
}

void Controller::addDogToDoglist(const Dog & dog)
{
	this->doglist.add(dog);
}









