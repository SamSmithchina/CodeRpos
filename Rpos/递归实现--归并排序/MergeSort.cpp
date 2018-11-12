#include "MergeSort.h"
#include <iostream>
#include <time.h>

int main()
{
	int iArray[NUM];
	int i;

	//initiallise the array with rand();
	srand((unsigned )time(NULL));
	for (i = 0; i < NUM; i++) 
	{
		iArray[i] = rand() % 100;
	}

	Display(iArray);
 	int* iRes = NULL;
	iRes = MergeSort(iArray, 0, NUM - 1);
	
	Display(iArray);
	return 0;
}