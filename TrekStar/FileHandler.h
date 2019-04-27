#pragma once
#include <string>
#include "TeamRoles.h"
#include "Project.h"
#include "Stack.h"
#include <fstream>

class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	bool updateTeamRoles(std::vector<TeamRoles> tr);
	bool saveAllChanges(Stack projects);

	std::string getFileContent() { return this->fileContent; }


private:
	std::string fileContent;
	const std::string separator = ",";
	std::ofstream outStream;
};

