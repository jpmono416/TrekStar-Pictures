#pragma once
#include <string>
#include <vector>
#include <ostream>
class Genres
{
public:
	Genres();
	~Genres();
	void setID(int id);
	int getID() { return this->id; }
	std::string getGenre();
	friend std::basic_ostream<char, std::char_traits<char>>& operator<<(std::basic_ostream<char, std::char_traits<char>>& os, Genres genre);
private:
	int id;
	std::vector <std::string> genreList = {"Comedy","Horror", "Romance", "SciFi","Adventure", "Documentary", "Action","War", "Musical"};
};
