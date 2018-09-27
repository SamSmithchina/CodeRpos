#include "FileOperationHelper.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strFileName = "f:\\file\\ProjectWorkstation\\读写行情文件\\读写行情文件\\GodBlessYou.txt";
	std::cout << "文件路径 : " << strFileName << std::endl;

	WriteFile(strFileName);
	ReadFile(strFileName);

	
	system("pause");

}