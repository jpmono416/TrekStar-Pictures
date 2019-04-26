#pragma once
#include <string>
#include <vector>
class Genres
{
public:
	Genres();
	~Genres();
	void setID(int id);
	std::string getGenre();
private:
	int id;
	std::vector <std::string> genreList = {"Comedy","Horror", "Romance", "SciFi","Adventure", "Documentary", "Action","War", "Musical"};
};
