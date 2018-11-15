#include "ignore.h"
#include "include.h"
#include <iostream>
using namespace std;

//extern void GetAllFiles(const string strPath, vector<string> vctFileDataInfo,
//	const string strFormat);
//extern void CalcuFileTypes(const vector<string> vctFileDataInfo);

int main()
{
	/*
	 推荐用如下方法来得到当前程序所在目录比较安全：
	 void _splitpath( const char *path, char *drive, char *dir, char *fname, char *ext );
	 函数来分解开始提到的_pgmptr，然后再用
	 void _makepath( char *path, const char *drive, const char *dir, const char *fname, const char *ext );
	 函数来对分解后的路径进行组合。这两个函数结合起来功能强大，使用灵活，
	 基本上所有的有关目录和路径方面的操作都可以搞定。
	 */
	//system("echo %cd%"); //显示当前路径
	char szPath[256] = { "\0" };
	int n = GetModuleFileNameA(NULL, szPath, 256);
	(strrchr(szPath, '\\'))[0] = 0; // 删除文件名，只获得路径字串  
	string strPath = szPath; //程序所在路径
	//strPath = "E:\\ProgramWorkstation\\Rpository\\Rpos";
	vector<string> vctFileDataInfo;
	vector<string> vctFileFolderInfo;
	vctFileDataInfo.clear();

	string strFormat = "";
	GetAllFiles(strPath, vctFileDataInfo, vctFileFolderInfo, strFormat);

	std::cout << std::endl
		<< "----------------------------------------------" << std::endl
		<< "----------------------------------------------" << std::endl
		<< " 当前路径下所有文件：" << std::endl << std::endl;
	DispayFileList(vctFileDataInfo);

	//GetFilesAttributes(strPath, vctFileDataInfo);
	CalcuFileTypes(vctFileDataInfo);

	std::cout
		<< "----------------------------------------------" << std::endl
		<< "----------------------------------------------" << std::endl
		<< " 指定删除文件类型：" << std::endl
		<< " Debug\\, log\\,  bin\\, x64\\, lib\\, *.tlog\\" << std::endl
		<< " *.sln, *.sdf, *.opensdf, *.suo, *.vcxproj, *.filters"
		<< std::endl << std::endl;
	DelFolders(vctFileFolderInfo, strPath);
	DelFiles(vctFileDataInfo, strPath);

	system("pause");
	return 0;
}