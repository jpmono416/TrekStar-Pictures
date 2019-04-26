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
	std::string releaseDate; //TODO CHANGE SETTER
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
	int getProjectId() { return this->projectID; }
	void setTitle(std::string userFilmTitle);
	std::string getTitle() { return this->filmName; }
	void setSummary(std::string userFilmSummary);
	std::string getSummary() { return this->summary; }
	void setReleaseDate(std::string userReleaseDate);
	std::string getReleaseDate() { return this->releaseDate; }
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

