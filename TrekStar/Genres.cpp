#include "pch.h"
#include "Genres.h"


Genres::Genres()
{
}


Genres::~Genres()
{
}

void Genres::setID(int id)
{
	this->id = id;
}

std::string Genres::getGenre()
{
	return this->genreList.at(id);
}

std::basic_ostream<char, std::char_traits<char>>& operator<<(std::basic_ostream<char, std::char_traits<char>>& os, Genres genre)
{
	os << genre.getID();
	return os;
}