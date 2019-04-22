#pragma once
#include <string>
#include <list>
#include "Project.h"
#include "Stack.h"
class Admin
{
public:
	Admin();
	~Admin();

	// These functions access the stack
	Project getProject();
	Project getLastProject() { this->stack.pop(); }
	void sortStackAsc();
	void sortStackDesc();
	void sortStackByIdAsc();
	void sortStackByIdDesc();
	void populateStack();

	// These functions access the reporting API
	std::string genWeeklyBOReport();
	std::string genMaterialsSalesReport();

	// These functions access the file handler
	bool editTeamRole();
	bool addTeamRole();
	bool removeTeamRole();
	bool addProject();


private:

	Stack stack = Stack();
	int elementId;
	void askForID();

	// This function accesses the stack
	std::string getAllProjects();


};

