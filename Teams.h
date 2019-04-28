#pragma once
#include "TeamRoles.h"
#include <string>
class Teams
{
public:
	Teams();
	~Teams();
private:
	TeamRoles teamRole;
	std::string name;
};

