/****************************************************************** 
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		
* Description: 

* ***********************************************************************/

#ifndef __ANALYZE_H__
#define __ANALYZE_H__
#include <iostream>
#include <string>
using namespace std;

//输入： 两个不知道长度、内容的字符串；
//处理： 比较字符串的长度、包含的字符是否一致；
//	设置一个二维数组CharNum[2][26];记录两个字符串中26个字母出现的次数；
//输出： 如果一致就输出0， 否则 输出-1；
int Analyze(string str1, string str2)
{
	int CharNum[2][26] = { { 0 },{ 0 } };
	int str1Len = 0;
	int str2Len = 0;
	int  i = 0;
	int NE = 0;
	string::iterator strItor;

	for (i = 0; i < 26; i++)
	{
		CharNum[0][i] = 0;
		CharNum[1][i] = 0;
	}

	str1Len = str1.length();
	str2Len = str2.length();
	if (str1Len != str2Len)
	{
		return -1;
	}

	//第48～57号为0～9十个阿拉伯数字；65～90号为26个大写英文字母，97～122号为26个小写英文字母
	for (strItor = str1.begin(); strItor != str1.end(); strItor++)	//计算字母出现的次数， 不区分大小写
	{
		if (*strItor < 91 && *strItor > 64)	//大写字母
		{
			CharNum[0][*strItor - 65]++;
		}
		if (*strItor > 96 && *strItor < 123)//小写字母
		{
			CharNum[0][*strItor - 97]++;
		}
	}
//	cout << "*strItor = " << *strItor << endl;

	for (strItor = str2.begin(); strItor != str2.end(); strItor++)
	{
		if (*strItor < 91 && *strItor > 64)
		{
			CharNum[1][*strItor - 65]++;
		}
		if (*strItor < 123 && *strItor > 96)
		{
			CharNum[1][*strItor - 97]++;
		}
	}
	
	for (i = 0; i < 26; i++) // 比较结果；
	{
		if (CharNum[0][i] != CharNum[1][i])
		{
			if (NE == 0)
			{
				NE = -1;
			}
			cout << "character happens error :" <<(char)( i + 97) << endl;
		}
	}

	if (NE == -1)
	{
		std::cout << "str1 : " << str1 << "\nstr2 : " << str2 << "\n包含字符不相等" << endl;
		return -1;
	}

	return 0;
}


#endif