#pragma once
#include "Project.h"
#include <algorithm>
#include <iterator>
class Stack
{


private:

	static const int arraySize = 20;
	int amountOfElements = 0;
	// Assume the maximum elements that will be handled by this is 20 at a time
	Project data[arraySize];

public:
	Stack();
	~Stack();

	void emptyStack(Project* arrayData);
	Project getElem();
	bool addElem(Project elem);
	Project pop();
	
	int getArraySize() { return this->arraySize;  }
	int getAmountOfElements() { return this->amountOfElements; }
	void addToAmount() { ++amountOfElements;  }
	void removeFromAmount() { --amountOfElements; }
	Project* getData() { return this->data; }
	void setData(Project projects[arraySize]);

};