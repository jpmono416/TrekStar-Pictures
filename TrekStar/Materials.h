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
	void setTitle(std::string title);
	void setVideoFormat(int id);
	void setAudioFormat(int id);
	void setRunTime(long runTime);
	void setMainContent(std::string mainContent);
	void setLanguage(int id);
	void setRetailPrice(float retailPrice);
	void setSubtitles(bool subtitles);
	void setFrameAspect(std::string frameAspect);
	void setPackaging(int id);
	//void setMaterialType(enum materialType); //Not sure how to do with this?
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

