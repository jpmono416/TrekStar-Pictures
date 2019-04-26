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
		//this->outStream << teamRole.getId() 
		//	<< this->separator 
		//	<< teamRole.getName()
		//	<< std::endl;
	}
	this->outStream.close();
	return true;
}

bool FileHandler::updateProjects(Project proj[])
{
	const int arrayLength = sizeof(proj) / sizeof(Project);
	this->outStream.open("projects.csv");
	
	for (unsigned int counter = 0; counter <= arrayLength; ++counter)
	{
		Project pr = proj[counter];
		//this->outStream << pr.getProjectID()
			//<< this->separator
			//<< 

	}
	return true;
}
