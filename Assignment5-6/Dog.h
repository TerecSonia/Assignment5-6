#pragma once
#include <iostream>

using namespace std;

class Dog
{
private:
	string breed;
	string name;
	int age;
	string photograph;
public:
	///Default constructor
	Dog();

	///Copy constructor
	Dog(const string& breed, const string& name, const int& age, const string& photograph);

	/*Returns the breed of a dog
	IN:-
	OUT:this->breed-string
	*/
	string getBreed() const { return this->breed; }
	/*Returns the name of a dog
	IN:-
	OUT:this->name-string
	*/
	string getName() const { return this->name; }
	/*Returns the age of a dog
	IN:-
	OUT:this->age-int
	*/
	int getAge() const { return this->age; }
	/*Returns the photograph link of a dog
	IN:-
	OUT:this-photograph-string
	*/
	string getPhotograph() const { return this->photograph; }

	/*Open the photograph link in the browser
	IN:-
	OUT:-
	*/
	void play();
};
