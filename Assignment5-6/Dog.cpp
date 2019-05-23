#include "Dog.h"
#include <Windows.h>
#include <shellapi.h>

using namespace std;

Dog::Dog() : breed(""), name(""), age(0), photograph("") {}

Dog::Dog(const string& breed, const string& name, const int& age, const string& photograph)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photograph = photograph;
}

void Dog::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);
}