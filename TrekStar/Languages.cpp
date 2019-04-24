#include "pch.h"
#include "Languages.h"


Languages::Languages()
{
}


Languages::~Languages()
{
}

void Languages::setID(int id)
{
	this->id = id;
}

std::string Languages::getLanguage(int id)
{

	return this->items.at(id);
}
