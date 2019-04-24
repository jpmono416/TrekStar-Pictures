#pragma once
#include "Stack.h"
class BubbleSort
{
public:
	BubbleSort();
	~BubbleSort();

	void sortAsc();
	void sortDesc();
	void sortById(bool asc);

	Stack getStack() { return this->stack; }
	void setStack(Stack stack) { this->stack = stack; }
private:
	bool isBigger(int a, int b);
	Stack stack;
};

