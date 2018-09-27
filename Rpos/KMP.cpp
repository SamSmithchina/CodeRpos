//实现KMP算法， 掌握KMP算法在字符串匹配的高效原理

#include <iostream>
#include <string>


using namespace std;

//根据匹配字符串，求得该字符串在当前字符位置j时，下一次要匹配移动的字符数k ; next[j] =k;
// @input:
//		strAdapt, 匹配字符串
//	@output 
//		输出当前匹配串最大相同子串长度，即下次移动字符数的位置K，保存在数组 Next[]
int* KMP_Next(string strAdapt)
{
	int *iNext = new int[strAdapt.length()];

	iNext[0] = 0;
	int j = 1;
	int k = 0;
	cout << "Next[] {  0\t";
	while (j < (int)strAdapt.length() )
	{
		while (k > 0 && strAdapt.at(k) != strAdapt.at(j))
		{
			k = iNext[k - 1];
		}
		if (strAdapt.at(k) == strAdapt.at(j))
		{
			k++;
		}
	
		iNext[j++] = k;
		cout << k << "\t";
	}
	cout << " }" << endl;

	delete[] iNext;
}

//KMP算法，strAdapt字符串 对 strTarget字符串 进行匹配，
//常规字符串匹配是strAdapt逐字与目标串stTarget匹配，时间复杂度是O（Length(strTarget)* length(strAdapt));
//KMP算法思想是匹配串自身有从头部开始的子串strHeadSub，与在中间位置的子串strAnotherSub相同，下次匹配串就移动到相同子串strAmotherSub后面,
//需要用KMP_Next（)函数来计算匹配串不同位置的两个匹配子串长度，长度就是下一移动的位置；
//@input：
//		strAdapt 匹配串
//		strTarget 目标串
//@output :
//		iPosition 返回匹配串第一次匹配目标串的位置， 如果始终不匹配， 则输出-1；
int KMP(string strAdapt, string strTarget)
{
	int iTargetPos = 0;
	int iAdaptPos = 0;
	
	int iAdaptLength = strAdapt.length();	//注意避免访问越界，设置访问范围
	int *iNext = NULL;

	cout << "目标串 ： " << strTarget << endl;
	cout << "匹配串 ： " << strAdapt << endl;

	if (strAdapt.length() == 0 || strTarget.length() == 0)
	{
		cout << "字符串为空，无法进行匹配操作！ \n" << endl;
		exit(0);
	}

	iNext = KMP_Next(strAdapt);
	for (iTargetPos = 0,iAdaptPos = 0; iTargetPos <= (int)strTarget.length(); iTargetPos++ )
	{
		while(iAdaptPos > 0 && strAdapt[iAdaptPos] != strTarget[iTargetPos])
		{
			iAdaptPos = iNext[iAdaptPos];
		}
		if (strAdapt[iAdaptPos] == strTarget[iTargetPos])
		{
			iAdaptPos++;
		}
		if (iAdaptLength == iAdaptPos)
		{
			cout << "KMP 找到目标串匹配上匹配串，串尾位置 " << iTargetPos << endl;
			return iTargetPos;
		}

		
	}
	
	delete[] iNext;
	return -1;
}

int main()
{
	string strTarget = "ABCDEFGABCDHIJKABCABCDLMNABCDEFOPQRSTUVWXYZ";
	string strAdapt = "ABCDHIJKABCABCD";

	cout << "KMP ： " << KMP(strAdapt, strTarget) << std::endl;
	system("pause");
	return 0;
}
