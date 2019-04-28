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


std::basic_ostream<char, std::char_traits<char>>& operator<<(std::basic_ostream<char, std::char_traits<char>>& os, Languages& language)
{
	os << language.getID();
	return os;
}