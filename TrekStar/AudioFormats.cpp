#include "pch.h"
#include "AudioFormats.h"


AudioFormats::AudioFormats()
{
}


AudioFormats::~AudioFormats()
{
}

void AudioFormats::setID(int id)
{
	this->id = id;
}

std::string AudioFormats::getAudioFormat()
{
	return this->items.at(id);
}
