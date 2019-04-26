#pragma once
#include <string>
#include <vector>
class Languages
{
public:
	Languages();
	~Languages();
	void setID(int id);
	std::string getLanguage();
private:
	int id;
	std::vector <std::string> languageList = { "English", "Spanish", "Chinese", "German", "French", "Dutch", "Italian", "Russian", "Hindi" };
};
