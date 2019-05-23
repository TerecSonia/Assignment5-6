#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	///Copy constructor
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	///Validation data for command for menu
	bool validCommand(int command);

	///Validation data for command for administrator menu
	bool validCommandAdministrator(int commandRepo);

	///Validation data for command for user menu
	bool validCommandUser(int commandUser);

	///Validation data for age
	bool validAge(int age);

	///Prints the Menu
	static void printMenu();

	///Prints the Administrator Menu
	static void printRepositoryMenu();

	///Prints the User Menu
	static void printAdoptionListMenu();

	///Add a dog to the list
	void addDogUI();

	///Deletes a dog from the list
	void deleteDogUI();
	void updateDogUI();

	///Prints all dogs
	void printAllDogs();

	void printAdoptionMenu();

	///See all dogs one by one
	void seeAllDogsOneByOne();

	///See all dogs of a given breed having an age less than a given number
	void seeAllDogsByBreedAndAge();

	///See the adoption list
	void printAdoptionList();
};

