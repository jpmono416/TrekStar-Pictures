#pragma once
#include <string>
class TeamRoles
{
public:
	TeamRoles();
	~TeamRoles();

	int getId() { return this->id; }
	std::string getName() { return this->name; }
private:
	int id;
	std::string name;
};

