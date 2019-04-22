#pragma once
#include <string>
#include "TeamRoles.h"
#include "Project.h"
#include "Stack.h"
class FileHandler
{
public:
	FileHandler();
	~FileHandler();

	bool addTeamRole(TeamRoles tr);
	bool removeTeamRol(int id);
	bool changeTRName(int id, std::string newName);
	bool addProject(Project proj);
	bool removeProject(int id);
	bool saveAllChanges(Stack projects, std::vector<TeamRoles> teamRoles);

};

