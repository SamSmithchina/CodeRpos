#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//替换目标串指定位置之后的字符
int main()
{
	string strSource = "J000000000";
	string strAlternate = "9876";
	string strRes;
	int i = 0;
	int iLen = 0;
	int iMaxRound = 9000000;

	cout << "循环次数 ： " << iMaxRound << endl;

	//方法一 ： str.replace()
	time_t tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			strSource = "J000000000";
			strSource.replace(strSource.length() - strAlternate.length(), strAlternate.length(), strAlternate);
		}
	}
	time_t tEnd = clock();
	cout << strSource << endl;
	cout << "方法一 replace() 转换 " << iMaxRound << " 次 ， 用时 ： " << tEnd - tBegin << endl;


	//方法二
	tBegin = clock();
	{

		for (i = 0; i < iMaxRound; i++)
		{

			strSource = "J000000000";
			strSource.erase(strSource.length() - strAlternate.length(), strAlternate.length());
			strSource += strAlternate;
		}
	}
	tEnd = clock();
	cout << strSource << endl;
	cout << "方法二 erase() operator+ 转换 " << iMaxRound << " 次 ， 用时 ： " << tEnd - tBegin << endl;

	//方法三
	tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			strSource = "J";
			iLen = strAlternate.length();
			switch (iLen)
			{
			case 1:
				strSource += "00000000";
				break;
			case 2:
				strSource += "0000000";
				break;
			case 3:
				strSource += "000000";
				break;
			case 4:
				strSource += "00000";
				break;
			case 5:
				strSource += "0000";
				break;
			case 6:
				strSource += "000";
				break;
			case 7:
				strSource += "00";
				break;
			case 8:
				strSource += "0";
				break;
			default:
				break;
			}
			strSource += strAlternate;
		}
	}
	tEnd = clock();
	cout << strSource << endl;
	cout << "方法三 operator+ 转换 " << iMaxRound << " 次 ， 用时 ： " << tEnd - tBegin << endl;

	return 0;
}

/*
循环次数 ： 9000000
J000009876
方法一 replace() 转换 9000000 次 ， 用时 ： 1764
J000009876
方法二 erase() operator+ 转换 9000000 次 ， 用时 ： 2170
J000009876
方法三 operator+ insert() 转换 9000000 次 ， 用时 ： 3059


*/
