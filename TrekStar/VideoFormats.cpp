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

std::string VideoFormats::getVideoFormat()
{
	return this->items.at(id);
}


