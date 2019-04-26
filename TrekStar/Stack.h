#pragma once
#include "Project.h"
class Stack
{
public:
	Stack();
	~Stack();

	Project* emptyStack();
	Project getElem();
	bool addElem(Project elem);
	Project pop();
	
	int getArraySize() { return this->arraySize;  }
	int getAmountOfElements() { return this->amountOfElements; }
	void addToAmount() { ++amountOfElements;  }
	void removeFromAmount() { --amountOfElements; }

private:

	static const int arraySize = 20;
	int amountOfElements = 0;
	// Assume the maximum elements that will be handled by this is 20 at a time
	Project data[arraySize];
};