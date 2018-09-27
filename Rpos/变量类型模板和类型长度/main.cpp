#include <iostream>
#include "ElementType.h"



int main()
{
	char szC = 'c';
	short sShort = 1;
	unsigned unsShort = 2;
	int i = 3;
	unsigned int uni = 4;
	long l = 5;
	unsigned long unl = 6;
	float f = 7;
	double d = 9;
	long long ll = 10;
	unsigned long long ull = 11;


	CalcElementSize(szC);


	CalcElementSize(sShort);


	CalcElementSize(unsShort);


	CalcElementSize(i);


	CalcElementSize(uni);


	CalcElementSize(l);


	CalcElementSize(unl);


	CalcElementSize(f);


	CalcElementSize(d);

	CalcElementSize(ll);

	CalcElementSize(ull);

	system("pause");
	return 0;
}