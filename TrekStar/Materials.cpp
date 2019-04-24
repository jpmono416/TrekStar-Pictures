#include "pch.h"
#include "Materials.h"


Materials::Materials()
{
}


Materials::~Materials()
{
}

void Materials::setid(int id)
{
	this->id = id;
}

void Materials::setTitle(std::string title)
{
	this->title = title;
}

void Materials::setVideoFormat(int id)
{
	VideoFormats videoFormat;
	videoFormat.setID(id);
	this->videoFormat = videoFormat;
}

void Materials::setAudioFormat(int id)
{
	AudioFormats audioFormats;
	audioFormat.setID(id);
	this->audioFormat = audioFormat;
}

void Materials::setRunTime(long runTime)
{
	this->runTime = runTime;
}

void Materials::setMainContent(std::string mainContent)
{
	this->mainContent = mainContent;
}

void Materials::setLanguage(int id)
{
	Languages language;
	language.setID(id);
	this->language = language;
}

void Materials::setRetailPrice(float retailPrice)
{
	this->retailPrice = retailPrice;
}

void Materials::setSubtitles(bool subtitles)
{
	this->subtitles = subtitles;
}

void Materials::setFrameAspect(std::string frameAspect)
{
	this->frameAspect = frameAspect;
}

void Materials::setPackaging(int id)
{
	Packaging packaging;
	packaging.setID(id);	
	this->packaging = packaging;
}

void Materials::setMaterialType(int id)
{
	switch (id) {
	case 1:
		this->materialType = SingleDVD;
		break;
	case 2:
		this->materialType = DoubleDVD;
		break;
	case 3:
		this->materialType = BluRay;
		break;
	case 4:
		this->materialType = ComboBox;
		break;
	case 5:
		this->materialType = VHS;
		break;
	}
	this->materialType = SingleDVD;
}
