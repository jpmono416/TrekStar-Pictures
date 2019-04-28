#include "pch.h"
#include "Packaging.h"


Packaging::Packaging()
{
}


Packaging::~Packaging()
{
}

void Packaging::setID(int id)
{
	this->id = id;
}

int Packaging::getID()
{
	return this->id;
}

std::string Packaging::getPackaging()
{
	return this->items.at(id);
}

