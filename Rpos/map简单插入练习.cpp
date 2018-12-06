/****************************************************************** 
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		2018年7月17日15:51:253
* Description:  练习map STL标准模板库；

* ***********************************************************************/

#include <iostream>
#include <map>

using namespace std;
int main()
{
	map<int, string> myMap;
	std::pair<std::map<int, string>::iterator, bool> iter;
	iter = myMap.insert(std::pair<int, string>(1, "11"));
	if (iter.second == false)
	{
		cout << "插入失败";
	}
	return 0;
}
