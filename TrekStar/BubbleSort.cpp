#include "pch.h"
#include "BubbleSort.h"


BubbleSort::BubbleSort()
{
}


BubbleSort::~BubbleSort()
{
}

bool inline BubbleSort::isBigger(int a, int b)
{
	return(a > b);
}

//void BubbleSort::sortById(bool asc)
//{
//	bool newIteration = true;
//	const int dataSize = this->stack.getData().size();
//
//	while (newIteration)
//	{
//		newIteration = false;
//		for (int id = 0; id <= dataSize; ++id)
//		{
//			Project project = stack.getData[id];
//			Project next = stack.getData[id + 1];
//			
//			if (isBigger(project.getId(), next.getId()))
//			{
//				if (asc)
//				{
//					stack.getData[id + 1] = project;
//					stack.getData[id] = next;
//				}
//				else
//				{
//					stack.getData[id] = project;
//					stack.getData[id + 1] = next;
//				}
//					
//				newIteration = true;
//			}
//		}
//	}
//}
