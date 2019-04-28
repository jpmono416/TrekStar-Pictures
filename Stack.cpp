#include "pch.h"
#include "Stack.h"

Stack::Stack()
{
}


Stack::~Stack()
{
}

// Return the data in  the order which the stack will process
void Stack::emptyStack(Project *arrayData)
{
	int arrayCounter = 0;
	// Iterate backwards through the vector
	int size = (sizeof(data) / sizeof(Project));
	while (size >= 0 && arrayCounter <= 19)
	{
		arrayData[arrayCounter] = (this->pop());
		++arrayCounter;
	}
}


// Remove the last element of the stack and return it
Project Stack::pop()
{
	Project * tempArray[] { new Project[(sizeof(data) / sizeof(Project)) - 1] };
	Project rtnProj = getElem();
	
	memcpy(data, tempArray, sizeof(tempArray));
	removeFromAmount();
	return rtnProj;
}

void Stack::setData(Project projects[arraySize])
{
	for (unsigned int i = 0; i < arraySize; ++i)
	{
		this->data[i] = projects[i];
	}
}



Project Stack::getElem()
{
	return data[(sizeof(data) / sizeof(Project)) - 1];
}

bool Stack::addElem(Project elem)
{
	if (getAmountOfElements() < getArraySize())
	{
		data[getAmountOfElements()] = elem;
		addToAmount();
		return true;
	}
	return false;
}
