#pragma once
#include <string>
#include <vector>
#include <ostream>
class Locations
{
public:
	Locations();
	~Locations();
	void setID(int id);
	int getID();
	std::string getLocation();
	friend std::basic_ostream<char, std::char_traits<char>>& operator<<(std::basic_ostream<char, std::char_traits<char>>& os, Locations& loc);

private:
	int id;
	std::vector <std::string> locationList = { "UK", "USA", "China", "Germany", "France", "Netherlands", "Italy", "Russia", "India" };
};

