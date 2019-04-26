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
