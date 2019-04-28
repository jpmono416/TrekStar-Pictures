#include "pch.h"
#include "VideoFormats.h"


VideoFormats::VideoFormats()
{
}


VideoFormats::~VideoFormats()
{
}

void VideoFormats::setID(int id)
{
	this->id = id;
}

int VideoFormats::getID()
{
	return this->id;
}

std::string VideoFormats::getVideoFormat()
{
	return this->items.at(id);
}


