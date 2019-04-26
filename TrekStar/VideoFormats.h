#pragma once
#include <string>
#include <vector>
class VideoFormats
{
public:
	VideoFormats();
	~VideoFormats();
	void setID(int id);
	std::string getVideoFormat(int id);
private:
	int id;
	std::vector <std::string> items = { "MP4", "AVI", "WPA" };
};

