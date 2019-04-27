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

int Locations::getID()
{
	return this->id;
}
std::string Locations::getLocation()
{
	return this->locationList.at(id);
}


std::basic_ostream<char, std::char_traits<char>>& operator<<(std::basic_ostream<char, std::char_traits<char>>& os, Locations& loc)
{
	os << loc.getID();
	return os;
}
