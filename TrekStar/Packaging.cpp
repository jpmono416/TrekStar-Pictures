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

std::string Packaging::getPackaging()
{
	return this->items.at(id);
}

