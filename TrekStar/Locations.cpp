#include "pch.h"
#include "Locations.h"


Locations::Locations()
{
}


Locations::~Locations()
{
}

void Locations::setID(int id)
{
	this->id = id;
}

std::string Locations::getLocation()
{

	return this->locationList.at(id);
}