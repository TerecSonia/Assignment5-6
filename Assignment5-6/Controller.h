#pragma once
#include "Repository.h"
#include "Doglist.h"
#include <iostream>

using namespace std;

class Controller
{
private:
	Repository repo;
	Doglist doglist;
public:
	///Copy constructor
	Controller(const Repository& repo, const Doglist& doglist);

	/*Returns the repository of the controller
	IN:-
	OUT:this->repo-Repository
	*/
	Repository getRepo()const { return this->repo; }


	/*Returns the doglist of the controller
	IN:-
	OUT:this->doglist-Doglist
	*/
	Doglist getDogList() const { return this->doglist; }

	/*Adds a dog to the repository of the controller
	IN:breed-string,name-string,age-int,photograph-string
	OUT:true-bool (the dog was added)
		false-bool(the dog already exists)
	*/
	bool addDogCtrl(const string& breed, const string& name, const int& age, const string& photograph);

	/*Deletes a dog fro the repository of the controller
	IN:name-string,age-int
	OUT:true-bool (the dog was deletes)
		false-bool(the dog doesn't exist)
	*/
	bool deleteDogCtrl(const string& name, const int& age);

	/*Updates a dog from the repository of the controller
	IN:name-string,age-int
	OUT:true-bool (the dog was updated)
		false-bool(the dog doesn't exist)
	*/
	bool updateDogCtrl(const string& name, const int& age, const Dog& dog);

	/*Adds a dog to the doglist of the controller
	IN:dog-Dog
	OUT:-
	*/
	void addDogToDoglist(const Dog& dog);

};

