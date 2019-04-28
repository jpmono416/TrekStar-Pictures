#include "pch.h"
#include "Project.h"
#include "Materials.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <cctype>
#include <ctime>


Project::Project()
{
}


Project::~Project()
{
}
void Project::setProjectID(int ID)
{

	this->projectID = ID;
}

int Project::getProjectID() const
{
	return this->projectID;
}

void Project::setTitle(std::string userFilmTitle)
{
	this->filmTitle = userFilmTitle;
}

std::string Project::getTitle()
{
	return this->filmTitle;
}

void Project::setSummary(std::string userFilmSummary)
{
	this->summary = userFilmSummary;
}

std::string Project::getSummary()
{
	return this->summary;
}

void Project::setReleaseDate(std::string releaseDate)
{
	tm userReleaseDate;
	char dateInput[11];
	int dd, mm, yy;
	strcpy_s(dateInput, releaseDate.c_str());

	sscanf_s(dateInput,"%d/%d/%d",&dd,&mm,&yy);
	userReleaseDate.tm_mday = dd;
	userReleaseDate.tm_mon = mm;
	userReleaseDate.tm_year = yy;

	this->releaseDate = userReleaseDate;
}

std::string Project::getReleaseDateAsString()
{
	int const bufferSize = 11;
	char dateStr[bufferSize];
	strftime(dateStr, bufferSize, "%d/%m/%Y", &this->getReleaseDate());
	return dateStr;
}


tm Project::getReleaseDate()
{
	return this->releaseDate;
}

void Project::setGenre(int userGenre)
{
	Genres genre;
	genre.setID(userGenre-1);
	this->genre = genre;
}

Genres Project::getGenre()
{
	return this->genre;
}

void Project::setLanguages(int userLanguage)
{
	Languages language;
	language.setID(userLanguage);
	this->languages.push_back(language);
}

std::vector<Languages> Project::getLanguages()
{
	return this->languages;
}

void Project::setLocations(int userLocations)
{
	Locations location;
	location.setID(userLocations);
	this->locations.push_back(location);
}

std::vector<Locations> Project::getLocations()
{
	return this->locations;
}

void Project::setRuntime(int runTime)
{
	this->runTime = runTime;
}

int Project::getRuntime()
{
	return this->runTime;
}

void Project::setKeywords(std::string userKeywords)
{
	this->keywords.push_back(userKeywords);
}

std::vector<std::string> Project::getKeywords()
{
	return this->keywords;
}

void Project::setFilmStatus(int userFilmStatusID)
{
	this->filmStatusID = userFilmStatusID-1;
}

int Project::getFilmStatus()
{
	return this->filmStatusID;
}

void Project::setTicketSales(int userTicketSales)
{
	this->weeklyTicketSales = userTicketSales;
}

int Project::getTicketSales()
{
	return this->weeklyTicketSales;
}

std::vector<Materials> Project::getMaterials()
{
	return this->materials;
}

void Project::setMaterials(std::vector<Materials> material)
{
	this->materials = materials;
}

void Project::addMaterial(Materials mat)
{
	this->materials.emplace_back(mat);
}

//Validation function
bool isInputStringValid(std::string stringCheck)
{
	if (stringCheck.size() == 0)
	{
		std::cout << "Input empty! Please try again!\n\n";
		return false;
	}
	else if (stringCheck.find(",") != std::string::npos)
	{
		std::cout << "Input contains comma! please try again without the comma!\n\n";
		return false;
	}
	else
	{
		return true;
	}
}

//Display functions
void clearScreen()
{
	system("CLS");
}
//Displaying project functions
std::string releaseDateToString(tm releaseDateString)
{
	std::string DateString;

	DateString.append(std::to_string(releaseDateString.tm_mday));
	DateString.append("/");
	DateString.append(std::to_string(releaseDateString.tm_mon));
	DateString.append("/");
	DateString.append(std::to_string(releaseDateString.tm_year));

	return DateString;
}

std::string genreToString(Genres genreString)
{
	return genreString.getGenre();
}

std::string languagesToString(std::vector<Languages> languageString)
{
	std::string LanguagesToString;
	int vectorSize = languageString.size();
	Languages x;

	for (int i = 0; i < vectorSize; i++)
	{
		x = languageString[i];
		LanguagesToString.append(x.getLanguage());
		if (i != vectorSize-1)
		{
			LanguagesToString.append(", ");
		}
	}
	return LanguagesToString;
}
std::string locationsToString(std::vector<Locations> locationString)
{
	std::string LocationsToString;
	int vectorSize = locationString.size();
	Locations x;

	for (int i = 0; i < vectorSize; i++)
	{
		x = locationString[i];
		LocationsToString.append(x.getLocation());
		if (i != vectorSize - 1)
		{
			LocationsToString.append(", ");
		}
	}
	return LocationsToString;
}

std::string runtimeToString(int runtimeString)
{
	return std::to_string(runtimeString);
}

std::string keywordsToString(std::vector<std::string> keywordStrings)
{
	std::string keywordsToString;
	int vectorSize = keywordStrings.size();
	for (int i = 0; i < vectorSize; i++)
	{
		keywordsToString.append(keywordStrings[i]);
		if (i != vectorSize - 1)
		{
			keywordsToString.append(", ");
		}
	}
	return keywordsToString;
}

std::string filmStatusToString(int filmStatusString)
{
	std::vector <std::string> filmStatusList = { "Unreleased", "Now Playing", "Released" };
	return filmStatusList[filmStatusString];
}

std::string ticketSalesToString(int ticketSales)
{
	return std::to_string(ticketSales);
}

//Project Creation function
void newProject()
{
	Project newProject;
	Stack stack;
	std::string projectID, title, summary, releaseDate, genre, languages, locations, runtime, keywords, filmStatus, ticketSales;
	bool format = false, addMore = true;
	int  ID = NULL,genreID = NULL, languageID = NULL, locationID = NULL, runtimeID = NULL, filmStatusID = NULL, ticketSalesInt = NULL;
	clearScreen();
	//ID Input
	while (format == false)
	{
		std::cout << "Enter Project ID: ";
		std::cin >> projectID;
		bool has_only_digits = (projectID.find_first_not_of("0123456789") == std::string::npos);
		if (has_only_digits == true)
		{
			ID = std::stoi(projectID);
			format = true;
		}
		else
		{
			std::cout << "Please enter numbers only!\n";
		}

	}
	newProject.setProjectID(ID);
	std::cin.ignore(); //clears cin to avoid duplicate cout
	format = false;
	clearScreen();

	//Title input
	while (format == false)
	{
		std::cout << "Enter Film Title: ";
		std::getline(std::cin, title);
		if (isInputStringValid(title) != false)
		{
			format = true;
		}
	}
	newProject.setTitle(title);
	format = false;
	clearScreen();

	//Summary input
	while (format == false)
	{
		std::cout << "Enter Film Summary: ";
		std::getline(std::cin, summary);
		if (isInputStringValid(summary) != false)
		{
			format = true;
		}
	}
	newProject.setSummary(summary);
	format = false;
	clearScreen();

	//Release date input
	while (format == false)
	{
		char dateInput[11];
		std::cout << "Enter Film Release Date in the format of DD/MM/YYYY: ";
		std::cin >> releaseDate;
		if (releaseDate.length() == 10)
		{
			strcpy_s(dateInput, releaseDate.c_str());
			if ((isdigit(dateInput[0]) != 0) & (isdigit(dateInput[1]) != 0))
			{
				if (dateInput[2] == '/')
				{
					if ((isdigit(dateInput[3]) != 0) & (isdigit(dateInput[4]) != 0))
					{
						if (dateInput[5] == '/')
						{
							if ((isdigit(dateInput[6]) != 0) & (isdigit(dateInput[7]) != 0) & (isdigit(dateInput[8]) != 0) & (isdigit(dateInput[9]) != 0))
							{
								format = true;
							}
						}
					}
				}
			}
		}
		if (format == false)
		{
			std::cout << "Invalid date format! Please try again!\n";
		}
	}
	newProject.setReleaseDate(releaseDate);
	format = false;
	clearScreen();

	//Genre input
	while (format == false)
	{
		std::cout << "Enter Film genre. (1, Comedy  2, Horror  3, Romance  4, SciFi  5, Adventure  6, Documentary  7, Action  8, War  9, Musical): ";
		std::cin >> genre;
		if (genre.length() == 1 & isdigit(genre[0]) != 0 & genre[0] != '0')
		{
			genreID = std::stoi(genre);
			format = true;
			break;
		}
		std::cout << "Invalid genre input! Please pick a number between 1-9!\n";
	}
	newProject.setGenre(genreID);
	format = false;
	clearScreen();

	//Languages input
	while (addMore == true)
	{
		while (format == false)
		{
			bool responseFormat = false;
			std::cout << "Enter language. (1, English  2, Spanish  3, Chinese  4, German  5, French  6, Dutch  7, Italian  8, Russian  9, Hindi): ";
			std::cin >> languages;
			if (languages.length() == 1 & isdigit(languages[0]) != 0 & languages[0] != '0')
			{
				languageID = std::stoi(languages);
				newProject.setLanguages(languageID);
				while (responseFormat == false)
				{
					std::string response = "";
					std::cout << "\nDo you want to add another language (y/n): ";
					std::cin >> response;
					std::transform(response.begin(), response.end(), response.begin(), ::tolower);
					if (response == "y")
					{
						responseFormat = true;
						format = false;
						break;
					}
					if (response == "n")
					{
						addMore = false;
						responseFormat = true;
						format = true;
						break;
					}
					if (responseFormat == false)
					{
						std::cout << "Invalid input! Type 'y' to add another language or 'n' to continue adding project\n";
					}
				}
			}
			else
			{
				std::cout << "Invalid language input! Please pick a number between 1-9!\n";
			}
		}
	}
	format = false;
	addMore = true;
	clearScreen();

	//Locations input
	while (addMore == true)
	{
		while (format == false)
		{
			bool responseFormat = false;
			std::cout << "Enter Location. (1, UK  2, USA  3, China  4, Germany  5, France  6, Netherlands  7, Italy  8, Russia  9, India): ";
			std::cin >> locations;
			if (locations.length() == 1 & isdigit(locations[0]) != 0 & locations[0] != '0')
			{
				locationID = std::stoi(locations);
				newProject.setLocations(locationID);
				while (responseFormat == false)
				{
					std::string response = "";
					std::cout << "\nDo you want to add another language (y/n): ";
					std::cin >> response;
					std::transform(response.begin(), response.end(), response.begin(), ::tolower);
					if (response == "y")
					{
						responseFormat = true;
						format = false;
						break;
					}
					if (response == "n")
					{
						addMore = false;
						responseFormat = true;
						format = true;
						break;
					}
					if (responseFormat == false)
					{
						std::cout << "Invalid input! Type 'y' to add another location or 'n' to continue adding project\n";
					}
				}
			}
			else
			{
				std::cout << "Invalid location input! Please pick a number between 1-9!\n";
			}
		}
	}
	format = false;
	addMore = true;
	clearScreen();

	//Runtime input
	while (format == false)
	{
		std::cout << "Enter Film Runtime in minutes: ";
		std::cin >> runtime;
		bool has_only_digits = (runtime.find_first_not_of("0123456789") == std::string::npos);
		if (has_only_digits == true)
		{
			runtimeID = std::stoi(runtime);
			format = true;
		}
		else
		{
			std::cout << "Please enter numbers only!\n";
		}
	}
	newProject.setRuntime(runtimeID);
	format = false;
	clearScreen();

	//Keywords input
	while (addMore == true)
	{
		while (format == false)
		{
			bool responseFormat = false;
			std::cin.ignore();
			std::cout << "Enter a Film Keyword: ";
			std::getline(std::cin,keywords);
			if (isInputStringValid(keywords) != false)
			{
				newProject.setKeywords(keywords);
				format = true;

				while (responseFormat == false)
				{
					std::string response = "";
					std::cout << "\nDo you want to add another keyword (y/n): ";
					std::cin >> response;
					std::transform(response.begin(), response.end(), response.begin(), ::tolower);
					if (response == "y")
					{
						responseFormat = true;
						format = false;
						break;
					}
					if (response == "n")
					{
						addMore = false;
						responseFormat = true;
						format = true;
						break;
					}
					if (responseFormat == false)
					{
						std::cout << "Invalid input! Type 'y' to add another location or 'n' to continue adding project\n";
					}
				}
			}
		}
	}
	format = false;
	clearScreen();

	//Film status input
	while (format == false)
	{
		std::cout << "Enter Film status (1, Unreleased  2, Now Playing  3, Released): ";
		std::cin >> filmStatus;
		bool has_only_digits = (filmStatus.find_first_not_of("123") == std::string::npos);
		if (has_only_digits == true)
		{
			filmStatusID = std::stoi(filmStatus);
			format = true;
		}
		else
		{
			std::cout << "Please enter numbers 1, 2 or 3 only!\n";
		}

	}
	newProject.setFilmStatus(filmStatusID);
	format = false;
	clearScreen();

	if (filmStatus == "2")
	{
		while (format == false)
		{
			std::cout << "Enter Weekly Ticket Sales to the nearest Pound: ";
			std::cin >> ticketSales;

			bool has_only_digits = (ticketSales.find_first_not_of("0123456789") == std::string::npos);
			if (has_only_digits == true)
			{
				ticketSalesInt = std::stoi(ticketSales);
				format = true;
			}
			else
			{
				std::cout << "Please enter numbers only!\n";
			}

		}
		newProject.setTicketSales(ticketSalesInt);
	}
	clearScreen();
	//Print out project details
	std::cout << newProject;
	/*
	std::cout << "Project ID: " << std::to_string(newProject.getProjectID()) << std::endl;
	std::cout << "Project Title: " << newProject.getTitle() << std::endl;
	std::cout << "Project Summary: " << newProject.getSummary() << std::endl;
	std::cout << "Project Release Date: " << releaseDateToString(newProject.getReleaseDate()) << std::endl;
	std::cout << "Project Genre: " << genreToString(newProject.getGenre()) << std::endl;
	std::cout << "Project languages: " << languagesToString(newProject.getLanguages()) << std::endl;
	std::cout << "Project locations: " << locationsToString(newProject.getLocations()) << std::endl;
	std::cout << "Project Runtime: " << runtimeToString(newProject.getRuntime()) << " minutes" << std::endl;
	std::cout << "Project Keywords: " << keywordsToString(newProject.getKeywords()) << std::endl;
	std::cout << "Project Status: " << filmStatusToString(newProject.getFilmStatus()) << std::endl;
	std::cout << "Project Weekly Ticket Sales: " << ticketSalesToString(newProject.getTicketSales()) << std::endl;
	*/

	std::cout << "Project " + projectID + " Created!\n\n";
	stack.addElem(newProject);
}

/* 
*	Override of the << operator that manipulates the underlying 
*	classes, which have an override too, to return it to the 
*	file manipulator class
*/
std::basic_ostream<char, std::char_traits<char>>& operator<<(std::basic_ostream<char, std::char_traits<char>>& os, Project& pro)
{
	const char comma = ',';
	const char smColon = ';';
	std::string listBeginning = "[";
	std::string listEndings = "],";
	os << pro.getProjectID() << comma
		<< pro.getTitle() << comma
		<< pro.getSummary() << comma
		<< pro.getReleaseDateAsString() << comma
		<< pro.getGenre() << comma
		<< pro.getRuntime() << comma
		<< pro.getFilmStatus() << comma
		<< pro.getTicketSales() << comma;

	// Iterate through the lists of elements to get and format IDS
	// onto the CSV
	os << listBeginning;

	for (auto location : pro.getLocations())
	{
		os << smColon << location;
	}
	
	os << listEndings << listBeginning;
	
	for (auto language : pro.getLanguages())
	{
		os << smColon << language;
	}
	os << listEndings << listBeginning;

	for (auto keyword : pro.getKeywords())
	{
		os << smColon << keyword;
	}
	os << listEndings << listBeginning;

	for (auto material : pro.getMaterials())
	{
		os << material.getID();
	}
	
	os << listEndings;
	
	return os;
}

