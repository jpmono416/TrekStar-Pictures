#pragma once
#include <string>
#include <vector>
class Languages
{
public:
	Languages();
	~Languages();
	void setID(int id);
	std::string getLanguage(int id);
private:
	int id;
	std::vector <std::string> items = { "English","Spanish", "Chinese" };
};

