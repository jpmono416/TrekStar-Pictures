#pragma once
#include <string>
#include <vector>
#include "Locations.h"
#include "Teams.h"
#include "Genres.h"
#include "Languages.h"

class Project
{
public:
	Project();
	~Project();
	int* calcRunTime();
	void release();
	void stopPlaying();
private:
	int id;
	std::string filmName;
	std::string summary;
	tm releaseDate;
	Genres genre;
	std::vector<Locations> locations;
	std::vector<Languages> languages;
	int weeklyTicketSales;
	long runTime;
	std::vector<std::string> keywordss;
};

