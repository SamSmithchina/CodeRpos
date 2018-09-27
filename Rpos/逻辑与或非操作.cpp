/****************************************************************** 
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		2018-07-10 11:06:22
* Description:  联系逻辑与、或、非、异或^;

* ***********************************************************************/

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	double d = 0;

	//https://blog.csdn.net/violet_echo_0908/article/details/47395875

	//C++不支持直接使用二进制的数,只支持8,10,16三种进制的直接定义

	d = 2 && 1;
	cout << "按位与 ：" << d << endl;	//a&b 与运算，会返回a和b中每个位（比特，即二进制）最小的值; 

	d = 2 | 0;
	cout << "按位或 ：" << d << endl;	//a|b 或运算，会返回a和b中每个位（比特，即二进制）最大的值; 

	d = 3 != 0;
	cout << "按位非 ：" << d << endl;

	d = 4 ^ 0;
	cout << "按位异或 ：" << d << endl;

	time_t begin;
	time_t end;
	time_t begin2;
	time_t end2;
	int i = 0;
	int iTimes = 10000000000;

	d = 2;
	begin = clock();
	{
		for (i = 0; i < iTimes; i++)
		{
			
			if (d && 0x0)
			{
				// nothing;
			}
		}
	}
	end = clock();

	begin2 = clock();
	{
		for (i = 0; i < iTimes; i++)
		{
			if (d == 0)
			{
				//nothing
			}
		}
	}
	end2 = clock();

	cout << "if (d && 0) 用时 " << end - begin << endl;
	cout << "if (d == 0) 用时 " << end2 - begin2<< endl;
	cin.get();
	return 0;

}

/*
if (d && 0) 用时 if (d == 0) 用时  差别很小。
*/