#pragma once
#include <string>
#include <vector>
class AudioFormats
{
public:
	AudioFormats();
	~AudioFormats();
	void setID(int id);
	int getID();
	std::string getAudioFormat();

private:
	int id;
	std::vector <std::string> items = {"Dolby", "Doliby Digital", "MPEG-1", "PCM", "DTS"};
};

