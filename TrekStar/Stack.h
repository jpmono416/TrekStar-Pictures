#pragma once
#include <list>
#include "Project.h"
class Stack
{
public:
	Stack();
	~Stack();
	
	void emptyStack();
	Project getElem(int id);
	bool addElem(Project elem);
	Project pop();
	
	std::list<Project> getData() { return this->data; }
	void setData(std::list<Project> data) { this->data = data; }
private:
	std::list<Project> data;
};

