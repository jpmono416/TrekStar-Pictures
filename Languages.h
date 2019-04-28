#pragma once
#include <string>
#include <vector>
#include <ostream>
class Languages
{
public:
	Languages();
	~Languages();
	void setID(int id);
	int getID() { return this->id; }
	std::string getLanguage();
	friend std::basic_ostream<char, std::char_traits<char>>& operator<<(std::basic_ostream<char, std::char_traits<char>>& os, Languages& language);
private:
	int id;
	std::vector <std::string> languageList = { "English", "Spanish", "Chinese", "German", "French", "Dutch", "Italian", "Russian", "Hindi" };
};
