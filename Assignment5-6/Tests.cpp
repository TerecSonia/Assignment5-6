#include "Tests.h"
#include <assert.h>
#include "Dog.h"
#include "Repository.h"
#include "Controller.h"
#include "DynamicVector.h"

void Tests::testDog()
{
	Dog d1{ "Pitbull","Rocky",3,"fdhytuaa" };
	assert(d1.getBreed() == "Pitbull");
	assert(d1.getName() == "Rocky");
	assert(d1.getAge() == 3);
	assert(d1.getPhotograph() == "fdhytuaa");

	d1.play();
}

void Tests::testDynamicVector()
{
	DynamicVector<Dog> dogs;
	Dog d1{ "Bichon","Daisy",1,"http://www.dogbreedclub.com/bichon-frise/" };
	Dog d2{ "Pitbull","Rocky",4,"https://www.allthingsdogs.com/pitbull-breeds-and-types-of-pitbulls/" };
	Dog d3{ "Pechinez","Bella",6,"https://petmark.org/caine/Pechinez" };
	
	dogs.add(d1);
	dogs.add(d2);
	assert(dogs.getSize() == 2);
	dogs.add(d3);
	assert(dogs.getSize() == 3);
	dogs.deleteElem(2);
	assert(dogs.getSize() == 2);

	DynamicVector<Dog> dogs1;
	dogs1.add(d1);
	dogs1.add(d2);
	dogs = dogs1;

	Dog d4 = dogs.getAllElems()[0];
	d4 = d1;
}

void Tests::testRepository()
{
	Repository repo{};
	Dog dog{ "Labrador","Azor",5,"dfkjej" };
	repo.addDog(dog);
	int res1 = repo.findByNameAndAge("Azor", 5);
	assert(res1 == 0);

	res1 = repo.findByNameAndAge("Bella", 2);
	assert(res1 == -1);

	Repository repo1{};
	bool res = repo1.addDog(dog);
	assert(res == true);
	assert(repo1.getDogs().getSize() == 1);

	Repository repo2{};
	Dog dog2{ "Labrador","Azor",5,"dfkjej" };
	repo2.addDog(dog);
	res = repo2.addDog(dog2);
	assert(res == false);
	assert(repo2.getDogs().getSize() == 1);

	Repository repo3{};
	repo3.addDog(dog);
	res = repo3.deleteDog("Azor", 5);
	assert(res == true);
	assert(repo3.getDogs().getSize() == 0);

	Repository repo4{};
	repo4.addDog(dog);
	repo4.deleteDog("Azor", 5);
	res = repo4.deleteDog("Azor", 5);
	assert(res == false);
	assert(repo4.getDogs().getSize() == 0);

	Repository repo5{};
	repo5.addDog(dog);
	Dog dog1{ "Pechinez","Mia",2,"ert6g" };
	res = repo5.updateDog("Azor", 5, dog1);
	assert(res == true);
	assert(repo5.getDogs().getSize() == 1);

	Repository repo6{};
	repo6.addDog(dog);
	res = repo6.updateDog("Azor", 2, dog1);
	assert(res == false);
	assert(repo6.getDogs().getSize() == 1);

}

void Tests::testController()
{
	Repository repo{};
	Doglist doglist{};
	Controller ctrl{ repo ,doglist };
	bool res = ctrl.addDogCtrl("Labrador", "Azor", 5, "cgbfd");
	assert(res == true);
	assert(ctrl.getRepo().getDogs().getSize() == 1);


	res = ctrl.addDogCtrl("Labrador", "Azor", 5, "cgbfd");
	assert(res == false);
	assert(ctrl.getRepo().getDogs().getSize() == 1);

	res = ctrl.deleteDogCtrl("Azor", 5);
	assert(res == true);
	assert(ctrl.getRepo().getDogs().getSize() == 0);

	ctrl.addDogCtrl("Labrador", "Azor", 5, "cgbfd");
	res = ctrl.deleteDogCtrl("Bella", 5);
	assert(res == false);
	assert(ctrl.getRepo().getDogs().getSize() == 1);

	
	Dog dog{ "Pechinez","Mia",2,"ert6g" };
	res = ctrl.updateDogCtrl("Azor", 5, dog);
	assert(res == true);
	assert(ctrl.getRepo().getDogs().getSize() == 1);

	ctrl.addDogCtrl("Labrador", "Azor", 5, "cgbfd");
	res = ctrl.updateDogCtrl("Azor", 12, dog);
	assert(res == false);
	assert(ctrl.getRepo().getDogs().getSize() == 2);

	
	Dog dog2{ "Labrador", "Azor", 5, "cgbfd" };
	ctrl.addDogToDoglist(dog2);
	assert(ctrl.getDogList().getDogs().getSize() == 1);

	Dog dog3 = ctrl.getDogList().getCurrentDog();

}

void Tests::testAll()
{
	testDog();
	testRepository();
	testController();
	testDynamicVector();
}
