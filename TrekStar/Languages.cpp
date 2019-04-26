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

std::string Languages::getLanguage()
{

	return this->languageList.at(id);
}
