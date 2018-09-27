/****************************************************************** 
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		2018-07-19 14:31:44
* Description:  在C++中使用dos命令切换路径

* ***********************************************************************/

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	system("echo %cd%");
	system("cd ..\\..\\");
	system("echo %cd%");
	system("cd ..\\Debug");
	system("..\\Debug\\dos.bat");
	system("echo %cd%");

	cin.get();
	return 0;
}