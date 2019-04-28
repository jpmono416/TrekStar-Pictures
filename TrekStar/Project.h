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
	std::string filmTitle;
	std::string summary;
	tm releaseDate;
	Genres genre;
	std::vector<Locations> locations;
	std::vector<Languages> languages;
	int filmStatusID;
	int weeklyTicketSales;
	int runTime;
	std::vector<std::string> keywords;
	std::vector<Materials> materials;
public:
	Project();
	~Project();
	//int* calcRunTime();
	//void release();
	//void stopPlaying();

	//Setting functions
	void setProjectID(int projectID);
	void setTitle(std::string userFilmTitle);
	void setSummary(std::string userFilmSummary);
	void setReleaseDate(std::string userReleaseDate);
	void setGenre(int genreID);
	void setLanguages(int languageID);
	void setLocations(int locationID);
	void setRuntime(int runTime);
	void setKeywords(std::string userKeywords);
	void setFilmStatus(int filmStatusID);
	void setTicketSales(int userTicketSales);
	void setMaterials(std::vector<Materials> material);
	void addMaterial(Materials mat);
	//Getting functions
	int getProjectID() const; 
	std::string getTitle();
	std::string getSummary();
	tm getReleaseDate();
	std::string getReleaseDateAsString();
	Genres getGenre();
	std::vector<Locations> getLocations();
	std::vector<Languages> getLanguages();
	int getRuntime();
	std::vector<std::string> getKeywords();
	int getFilmStatus();
	int getTicketSales();
	std::vector <std::string> filmStatusList = { "Unreleased", "Now Playing", "Released" };
	std::vector<Materials> getMaterials();
	friend std::basic_ostream<char, std::char_traits<char>>& operator<<(std::basic_ostream<char, std::char_traits<char>>& os, Project& pro);
};

