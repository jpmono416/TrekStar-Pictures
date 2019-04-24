#pragma once
#include <string>
#include <vector>
#include "Locations.h"
#include "Teams.h"
#include "Genres.h"
#include "Languages.h"
#include "Materials.h"

class Project
{
public:
	Project();
	~Project();
	int* calcRunTime();
	void release();
	void stopPlaying();

	int getId() { return this->id; }
	void setId(int id) { this->id = id; }
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
	std::vector<std::string> keywords;
	std::vector<Materials> materials;
};

