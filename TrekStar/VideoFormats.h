#pragma once
#include <string>
#include <vector>
class VideoFormats
{
public:
	VideoFormats();
	~VideoFormats();
	void setID(int id);
	int getID();
	std::string getVideoFormat();
private:
	int id;
	std::vector <std::string> items = { "MP4", "AVI", "WPA" };
};

