/****************************************************************** 
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		2018-07-06 13:53:38
* Description: 比较两个无序的字符串包含的字符是否相同。str1 =“123”， str2 ="132"; str1 = str2; 

* ***********************************************************************/

#include <iostream>
#include "Analyze.h"
#define str1 "AaBbCcd"
#define str2 "AaBbCcD"

using namespace std;

int main()
{
	int i = 0;
	
	if (Analyze(str1, str2))
	{
		cout << str1 << "\t" << str2 << endl;
	}

	return 0;
}