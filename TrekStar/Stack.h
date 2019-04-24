#pragma once
#include <list>
#include "Project.h"
class Stack
{
public:
	Stack();
	~Stack();
	
	std::vector<Project> emptyStack();
	Project getElem();
	bool addElem(Project elem);
	Project pop();
	
	std::vector<Project> getData() { return this->data; }
	void setData(std::vector<Project> data) { this->data = data; }
private:
	std::vector<Project> data;
};

