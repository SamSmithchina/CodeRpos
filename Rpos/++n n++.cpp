// 2018年10月16日 14点08分

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
	int iMaxRound = 1000000000;
	int i = 0;
	int n = 999999;
	int m = 999999;
	int iRes = 0;
	time_t tBegin;
	time_t tEnd;

	cout << "循环次数 ： " << iMaxRound << endl;
	n = 999999;
	tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			n++;
		}
	}
	tEnd = clock();
	cout << setw(8) << "n++; " << "用时(ms) ： " << (tEnd - tBegin) * 1000 / CLOCKS_PER_SEC << endl;

	m = 999999;
	tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			++m;
		}
	}
	tEnd = clock();
	cout << setw(8) << " ++m;" << "用时(ms) ： " << (tEnd - tBegin) * 1000 / CLOCKS_PER_SEC << endl;

	n = 999999;
	tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			iRes = n++;
		}
	}
	tEnd = clock();
	cout << setw(8) << " iRes = n++;" << "用时(ms) ： " << (tEnd - tBegin) * 1000 / CLOCKS_PER_SEC << endl;

	m = 999999;
	tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			iRes = ++m;
		}
	}
	tEnd = clock();
	cout << setw(8) << " iRes = ++m; " << "用时(ms) ： " << (tEnd - tBegin) * 1000 / CLOCKS_PER_SEC << endl;
	system("pause");
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
01125FF7  mov         eax,dword ptr [n]
01125FFA  add         eax,1
01125FFD  mov         dword ptr [n],eax

++m;
011260E8  mov         eax,dword ptr [m]
011260EB  add         eax,1
011260EE  mov         dword ptr [m],eax

iRes = n++;
00D761D9  mov         eax,dword ptr [n]
00D761DC  mov         dword ptr [iRes],eax
00D761DF  mov         ecx,dword ptr [n]
00D761E2  add         ecx,1
00D761E5  mov         dword ptr [n],ecx

iRes = ++m;
00D762D0  mov         eax,dword ptr [m]
00D762D3  add         eax,1
00D762D6  mov         dword ptr [m],eax
00D762D9  mov         ecx,dword ptr [m]
00D762DC  mov         dword ptr [iRes],ecx

//add 2018-11-19 17:32:48
n++ 和 ++m 的汇编语言结构一致，只是是用来不同的寄存器；
进一步解释寄存器
	{
	一般寄存器:AX、BX、CX、DX
	AX:累积暂存器，BX:基底暂存器，CX:计数暂存器，DX:资料暂存器

	索引暂存器:SI、DI
	SI:来源索引暂存器，DI:目的索引暂存器

	堆叠、基底暂存器:SP、BP
	SP:堆叠指标暂存器，BP:基底指标暂存器

	EAX、ECX、EDX、EBX：為ax,bx,cx,dx的延伸，各為32位元
	ESI、EDI、ESP、EBP：為si,di,sp,bp的延伸，32位元

	eax, ebx, ecx, edx, esi, edi, ebp, esp等都是X86 汇编语言中CPU上的通用寄存器的名称，是32位的寄存器。如果用C语言来解释，可以把这些寄存器当作变量看待。
	}
这里不清楚为何两者效率上有差别？

iRes = n++; 与 iRes = ++m；区别在于赋值的顺序先后不一致
*/