// 2018年10月16日 14点08分

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
	int iMaxRound = 1000000000;
	int i = 0;
	int n = 0;
	int m = 0;
	int iRes = 0;
	time_t tBegin;
	time_t tEnd;

	cout << "循环次数 ： " << iMaxRound << endl;
	n = 0;
	m = 0;
	tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			n++;
		}
	}
	tEnd = clock();
	cout << setw(8) << "n++; " << "用时(ms) ： " << tEnd - tBegin << endl;

	n = 0;
	m = 0;
	tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			++m;
		}
	}
	tEnd = clock();
	cout << setw(8) << " ++m;" << "用时(ms) ： " << tEnd - tBegin << endl;

	n = 0;
	m = 0;
	tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			iRes = n++;
		}
	}
	tEnd = clock();
	cout << setw(8) << " iRes = n++;" << "用时(ms) ： " << tEnd - tBegin << endl;

	n = 0;
	m = 0;
	tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			iRes = ++m;
		}
	}
	tEnd = clock();
	cout << setw(8) << " iRes = ++m; " << "用时(ms) ： " << tEnd - tBegin << endl;

	return 0;
}

/*
循环次数 ： 1000000000
n++; 用时(ms) ： 1918
++m;用时(ms) ： 1887
iRes = n++;用时(ms) ： 3377
iRes = ++m; 用时(ms) ： 2861


*/

/* 反汇编：
n++;
0117241A  mov         ecx,dword ptr [n]
0117241D  add         ecx,1
01172420  mov         dword ptr [n],ecx

++m;
008775E2  mov         edx,dword ptr [m]
008775E5  add         edx,1
008775E8  mov         dword ptr [m],edx

iRes = n++;
008C76BB  mov         eax,dword ptr [n]
008C76BE  mov         dword ptr [iRes],eax
008C76C1  mov         ecx,dword ptr [n]
008C76C4  add         ecx,1
008C76C7  mov         dword ptr [n],ecx

iRes = ++m;
01172683  mov         edx,dword ptr [m]
01172686  add         edx,1
01172689  mov         dword ptr [m],edx
0117268C  mov         eax,dword ptr [m]
0117268F  mov         dword ptr [iRes],eax

*/