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

	virtual int* calcRunTime() = 0;

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
	char mainContent[64];
	Languages language;
	float retailPrice;
	bool subtitles;
	std::string frameAspect;
	Packaging packaging;
	MaterialType materialType;
};

