#pragma once
#include <string>
#include <vector>
class Locations
{
public:
	Locations();
	~Locations();
	void setID(int id);
	std::string getLocation();
private:
	int id;
	std::vector <std::string> locationList = { "UK", "USA", "China", "Germany", "France", "Netherlands", "Italy", "Russia", "India" };
};

