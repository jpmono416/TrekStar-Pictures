#pragma once
#include <vector>
#include <string>
#include "TeamRoles.h"

class JsonManipulator
{
public:
	JsonManipulator();
	~JsonManipulator();

	//std::vector<Project> readProjectJSON(std::string jsonString);
	std::vector<TeamRoles> readTrJSON(std::string jsonString);
	//std::string createJSON(std::vector<Object> teamRoles);
	//std::string createJson(Stack stack);
private:
	//std::string deserializeObject(Object T elem);
};

