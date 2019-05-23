#include "Doglist.h"

Doglist::Doglist()
{
	this->currentPos = 0;
}

void Doglist::add(const Dog & d)
{
	this->dogs.add(d);
}

Dog Doglist::getCurrentDog()
{
	if (this->dogs.getSize() == this->currentPos)
		this->currentPos = 0;
	Dog currDog = this->dogs[currentPos];
	return currDog;
}













