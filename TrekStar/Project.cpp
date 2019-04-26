#include "pch.h"
#include "Project.h"
#include "Materials.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <ctype.h>


Project::Project()
{
}


Project::~Project()
{
}
void Project::setProjectID(int ID)
{

	projectID = ID;
}

void Project::setTitle(std::string userFilmTitle)
{
	filmName = userFilmTitle;
}

void Project::setSummary(std::string userFilmSummary)
{
	summary = userFilmSummary;
}

void Project::setReleaseDate(std::string userReleaseDate)
{
	//formatting to be completed turning it into a tm
	//releaseDate = userReleaseDate;
}

void Project::setGenre(std::string userGenre)
{
	//lookup strings in genre list and assign IDS
}

void Project::setLanguages(std::string userLanguages)
{
	//lookup strings in Languages list and assign IDS
}

void Project::setLocations(std::string userLocations)
{
	//lookup strings in Locations list and assign IDS
}

void Project::setRuntime(std::string runTime)
{
	//formatting to be completed turning it into a long
}

void Project::setKeywords(std::string userKeywords)
{
	//formatting to be completed turning it into a vector
}


void Project::setFilmStatus(std::string userFilmStatus)
{
	//1 = unrealeased 2= now playing 3= released
}

void Project::setTicketSales(std::string userTicketSales)
{
	//formatting to be completed turning it into a float
}

void Project::setMaterials(int ID, Materials material)
{
	//add materials to project using ID
	//ID = projectID
	materials.push_back(material);
}

bool isInputStringValid(std::string stringCheck)
{
	if (stringCheck.size() == 0)
	{
		std::cout << "Input empty! Please try again!\n";
		return false;
	}
	else if (stringCheck.find(",") != std::string::npos)
	{
		std::cout << "Input contains comma! please try again without the comma!\n";
		return false;
	}
	else
	{
		return true;
	}
}

void newProject()
{
	Project newProject;
	std::string projectID, title = "", summary, releaseDate, genre, languages, locations, runtime, keywords, filmStatus, ticketSales;
	bool format = false;
	int  ID = NULL;
	//ID Input
	while (format == false)
	{
		std::cout << "\nEnter Project ID: ";
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

	//Title input
	while (format == false)
	{
		std::cout << "\nEnter Film Title: ";
		std::getline(std::cin, title);
		if (isInputStringValid(title) != false)
		{
			format = true;
		}
	}
	newProject.setTitle(title);
	format = false;

	//Summary input
	while (format == false)
	{
		std::cout << "\nEnter Film Summary: ";
		std::getline(std::cin, summary);
		if (isInputStringValid(summary) != false)
		{
			format = true;
		}
	}
	newProject.setSummary(summary);
	format = false;

	//Release date input
	while (format == false)
	{
		std::cout << "\nEnter Film Release Date in the format of DD/MM/YYYY: ";
		std::cin >> releaseDate;
		if (releaseDate.length() == 10)
		{
			char dateInput[11];
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

	//Genre input
	std::cout << "\nEnter Film genre: ";
	std::cin >> genre;
	newProject.setGenre(genre);
	format = false;

	//Languages input
	std::cout << "\nEnter Film Languages seperated by a comma: ";
	std::cin >> languages;
	newProject.setLanguages(languages);
	//Locations input
	std::cout << "\nEnter Film Locations seperated by a comma: ";
	std::cin >> locations;
	newProject.setLocations(locations);
	//Runtime input
	std::cout << "\nEnter Film Runtime: ";
	std::cin >> runtime;
	newProject.setRuntime(runtime);
	//Keywords input
	std::cout << "\nEnter Film Keywords seperated by a comma: ";
	std::cin >> keywords;
	newProject.setKeywords(keywords);
	//Film status input
	std::cout << "\nEnter Film status (1=unreleased 2=now playing 3=released): ";
	std::cin >> filmStatus;
	newProject.setFilmStatus(filmStatus);

	if (filmStatus == "2")
	{
		std::cout << "\nEnter Weekly Ticket Sales: ";
		std::cin >> ticketSales;
		newProject.setTicketSales(ticketSales);
	}
	std::cout << "\n\nProject " + projectID + " Created!\n\n";
	//stack.addElem();
}