
#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include <iostream>
#include <string>
#include <iomanip>

#define NUM 20

//Display 
void Display(int* iArray)
{
	int i;
	for (i = 0; i < NUM; i++)
	{
		std::cout << std::setw(3) <<std::setiosflags(std::ios::left) << i;
	}
	std::cout << "|" << std::endl;
	for (i = 0; i < NUM; i++)
	{
		std::cout << " " << std::setw(3) << std::setiosflags(std::ios::left) << iArray[i];
	}
	std::cout << std::endl;
}

// merge to left and right branch int one composation
// input : iArray need be merged in ascending order, iBottom :begin of iArray, iMid : separator the array, iTop :the end of iArray
// output: return a array after merge
int* merge(int* iArray, int iBottom, int iMid, int iTop)
{
	int iLeftCursor = iBottom;
	int iRightCursor = iMid + 1;
	

	for (; iLeftCursor <= iMid && iRightCursor <= iTop; )
	{
		if (iArray[iLeftCursor] <= iArray[iRightCursor])
		{
			++iLeftCursor;
		}
		else //这里要做的不是交换，而是插入和移动数据
		{
			// store 
			int iTempElem = iArray[iRightCursor];
			//move
			for (int iTempPose = iRightCursor ; iTempPose > iLeftCursor; iTempPose--)
			{
				iArray[iTempPose] = iArray[iTempPose - 1];
			}
			iArray[iLeftCursor] = iTempElem;
			++iMid;
			++iRightCursor;
		}
	}
	return iArray;
}

// merge sort the target array from small one to big one
//input : int* iArray int iBottom: array bottom, int iTop :array top
//output : int* iRes 
int* MergeSort(int* iArray, int iBottom, int iTop)
{
	int iElemSize = iTop + 1 - iBottom;
	if (iArray == NULL || iElemSize < 1)
	{
		std::cout << "your input an illegal array, please check the input array !" << std::endl;
		return NULL;
	}
	if (iElemSize == 1)
	{
		return iArray;
	}

	if (iElemSize == 2)
	{
		if (iArray[iBottom] > iArray[iTop])
		{
			int iTemp = iArray[iTop];
			iArray[iTop] = iArray[iBottom];
			iArray[iBottom] = iTemp;
		}
		return iArray;
	}

	//divide  the array int two branch
	int iLeftBranchSzie = iElemSize / 2 + 1; //向上取整
	int iRightBranchSize = iElemSize - iLeftBranchSzie;
	int iMid = iBottom + iLeftBranchSzie - 1;
	//int * iLeftBranchArray = new int[iLeftBranchSzie + 1];
	iArray = MergeSort(iArray, iBottom, iMid);
	iArray = MergeSort(iArray, iMid + 1, iTop);

	iArray = merge(iArray, iBottom, iMid, iTop);
	return iArray;
}

#endif