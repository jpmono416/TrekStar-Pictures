#pragma once
#include "Stack.h"
class BubbleSort
{
public:
	BubbleSort();
	~BubbleSort();

	void sortAsc();
	void sortDesc();
	void sortByIdAsc();
	void sortByIdDesc();

private:
	bool isBigger(int a, int b);
	Stack stack;
};

