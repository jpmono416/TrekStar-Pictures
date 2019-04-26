#pragma once
#include <string>
#include <vector>
class Packaging
{
public:
	Packaging();
	~Packaging();
	void setID(int id);
	std::string getPackaging();
private:
	int id;
	std::vector <std::string> items = { "Cardboard", "Plastic" };
};

