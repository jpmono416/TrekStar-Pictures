#pragma once
#include <string>
#include "VideoFormats.h"
#include "AudioFormats.h"
#include "Packaging.h"
#include "Languages.h"


class Materials
{
public:
	Materials();
	~Materials();

	//virtual int* calcRunTime() = 0;
	void setid(int id);
	int getID() { return this->id; }
	void setTitle(std::string title);
	std::string getTitle();
	void setVideoFormat(int id);
	int getVideoFormat();
	void setAudioFormat(int id);
	int getAudioFormat();
	void setRunTime(long runTime);
	long getRunTime();
	void setMainContent(std::string mainContent);
	std::string getMainContent();
	void setLanguage(int id);
	int getLanguage();
	void setRetailPrice(float retailPrice);
	float getRetailPrice();
	void setSubtitles(bool subtitles);
	bool getSubtitles();
	void setFrameAspect(std::string frameAspect);
	std::string getFrameAspect();
	void setPackaging(int id);
	int getPackaging();
	void setMaterialType(int id);
	int getMaterialType();
	friend std::basic_ostream<char, std::char_traits<char>>& operator<<(std::basic_ostream<char, std::char_traits<char>>& os, Materials& mat);
private:
	enum MaterialType 
	{
		SingleDVD,
		DoubleDVD,
		BluRay,
		ComboBox,
		VHS
	};

	int id;
	std::string title;
	VideoFormats videoFormat;
	AudioFormats audioFormat;
	long runTime;
	std::string mainContent;
	Languages language;
	float retailPrice;
	bool subtitles;
	std::string frameAspect;
	Packaging packaging;
	MaterialType materialType;
};

