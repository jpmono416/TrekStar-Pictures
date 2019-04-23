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

void Materials::setVideoFormat(VideoFormats videoFormat)
{
	this->videoFormat = videoFormat;
}

void Materials::setAudioFormat(AudioFormats audioFormat)
{
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

void Materials::setLanguage(Languages laguage)
{
	this->language = laguage;
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

void Materials::setPackaging(Packaging packaging)
{
	this->packaging = packaging;
}
