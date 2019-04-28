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

std::string Materials::getTitle()
{
	return this->title;
}

void Materials::setVideoFormat(int id)
{
	VideoFormats videoFormat;
	videoFormat.setID(id);
	this->videoFormat = videoFormat;
}

int Materials::getVideoFormat()
{
	return this->videoFormat.getID();
}

void Materials::setAudioFormat(int id)
{
	AudioFormats audioFormats;
	audioFormat.setID(id);
	this->audioFormat = audioFormat;
}

int Materials::getAudioFormat()
{
	return this->audioFormat.getID();
}

void Materials::setRunTime(long runTime)
{
	this->runTime = runTime;
}

long Materials::getRunTime()
{
	return this->runTime;
}

void Materials::setMainContent(std::string mainContent)
{
	this->mainContent = mainContent;
}

std::string Materials::getMainContent()
{
	return this->mainContent;
}

void Materials::setLanguage(int id)
{
	Languages language;
	language.setID(id);
	this->language = language;
}

int Materials::getLanguage()
{
	return this->language.getID();
}

void Materials::setRetailPrice(float retailPrice)
{
	this->retailPrice = retailPrice;
}

float Materials::getRetailPrice()
{
	return this->retailPrice;
}

void Materials::setSubtitles(bool subtitles)
{
	this->subtitles = subtitles;
}

bool Materials::getSubtitles()
{
	return this->subtitles;
}

void Materials::setFrameAspect(std::string frameAspect)
{
	this->frameAspect = frameAspect;
}

std::string Materials::getFrameAspect()
{
	return this->frameAspect;
}

void Materials::setPackaging(int id)
{
	Packaging packaging;
	packaging.setID(id);	
	this->packaging = packaging;
}

int Materials::getPackaging()
{
	return this->packaging.getID;
}

void Materials::setMaterialType(int id)
{
	switch (id) {
	case 0:
		this->materialType = SingleDVD;
		break;
	case 1:
		this->materialType = DoubleDVD;
		break;
	case 2:
		this->materialType = BluRay;
		break;
	case 3:
		this->materialType = ComboBox;
		break;
	case 4:
		this->materialType = VHS;
		break;
	}
	//this->materialType = SingleDVD; ?
}

int Materials::getMaterialType()
{
	return this->materialType;
}

std::basic_ostream<char, std::char_traits<char>>& operator<<(std::basic_ostream<char, std::char_traits<char>>& os, Materials& mat)
{
	const char* comma = ",";
	os << mat.getID() << comma
		<< mat.getTitle() << comma
		<< mat.getVideoFormat() << comma
		<< mat.getVideoFormat() << comma
		<< mat.getRunTime() << comma
		<< mat.getMainContent() << comma
		<< mat.getLanguage() << comma
		<< mat.getRetailPrice() << comma
		<< mat.getSubtitles() << comma
		<< mat.getFrameAspect() << comma
		<< mat.getPackaging() << comma
		<< mat.getMaterialType();

	return os;
}