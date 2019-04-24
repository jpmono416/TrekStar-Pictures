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
private:
	int projectID;
	std::string filmName;
	std::string summary;
	tm releaseDate;
	Genres genre;
	std::vector<Locations> locations;
	std::vector<Languages> languages;
	int filmStatusID;
	float weeklyTicketSales;
	long runTime;
	std::vector<std::string> keywords;
	std::vector<Materials> materials;
public:
	Project();
	~Project();
	int* calcRunTime();
	void release();
	void stopPlaying();
	void setProjectID(int ID);
	void setTitle(std::string userFilmTitle);
	void setSummary(std::string userFilmSummary);
	void setReleaseDate(std::string userReleaseDate);
	void setGenre(std::string userGenre);
	void setLanguages(std::string userLanguages);
	void setLocations(std::string userLocations);
	void setRuntime(std::string runTime);
	void setKeywords(std::string userKeywords);
	void setFilmStatus(std::string userFilmStatus);
	void setTicketSales(std::string userTicketSales);
	void setMaterials(int ID, Materials material);
	//1
};

