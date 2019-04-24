#include "pch.h"
#include "Stack.h"


Stack::Stack()
{
}


Stack::~Stack()
{
	this->emptyStack();
}

std::vector<Project> Stack::emptyStack()
{
	// Return the data in  the order which the stack will process
	std::vector<Project> stackData;
	
	// Iterate backwards through the vector
	while(data.size() >= 0)
	{
		stackData.push_back(this->pop());
	}

	return stackData;
}


// Remove the last element of the stack and return it
Project Stack::pop()
{
	auto project = data.back();
	data.pop_back();
	
	return project;
}

Project Stack::getElem()
{
	return data.back();
}

bool Stack::addElem(Project elem)
{
	data.push_back(elem);
}