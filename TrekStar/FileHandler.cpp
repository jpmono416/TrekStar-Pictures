#include "pch.h"
#include "FileHandler.h"


FileHandler::FileHandler()
{
}


FileHandler::~FileHandler()
{
}

bool FileHandler::updateTeamRoles(std::vector<TeamRoles> tr)
{
	this->outStream.open("teamRoles.csv");
	for (auto teamRole : tr)
	{
		// Add all fields fields comma separated and new line
		// TODO overload << as with the Project
		this->outStream << teamRole.getId() 
			<< this->separator 
			<< teamRole.getName()
			<< std::endl;
	}
	this->outStream.close();
	return true;
}

bool FileHandler::saveAllChanges(Stack proj)
{
	Project* projects{ proj.getData() };
	const int arrayLength = sizeof(projects) / sizeof(Project);
	this->outStream.open("projects.csv");

	for (unsigned int counter = 0; counter <= arrayLength; ++counter)
	{
		Project pr = projects[counter];
		this->outStream << pr;
	}
	return true;
}

