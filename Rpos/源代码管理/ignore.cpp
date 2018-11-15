#include "ignore.h"
#include <iostream>
#include <Windows.h>
#include <io.h>			// struct _finddata_t fileinfo;
using namespace std;


//指定删除文件类型， 其中带_folder 后缀的为文件夹，
enum DelFileType
{
	debug_folder, log_folder, bin_folder, x64_folder, lib_folder,
	sln, sdf, opensdf, suo, vcxproj, filters
};

//比较当前文件是否是指定待删除的文件类型；
// input：  当前文件名称strFilename， int iFileOrFolder 文件=1  文件夹 =2
// output： 是指定文件返回0，        不是返回-1；
int FileNameCompare(const string& strFileName, int iFileOrFolder)
{
	string strType[12] = {
		"Debug", "log", "bin", "x64", "lib", ".tlog",
		".sln", ".sdf", ".opensdf", ".suo", ".vcxproj", "filters" };

	size_t iPos = -1;
	if (iFileOrFolder == 1)
	{
		for (int i = 0; i <= 11; i++)
		{
			iPos = strFileName.rfind(strType[i]); //文件夹下
			if (i < 6 && iPos != strFileName.npos)
			{
				return -1;
			}
			if (5 <i && iPos != strFileName.npos)//单个文件
			{
				return 0;
			}
		}
	}
	if (iFileOrFolder == 2)
	{
		for (int i = 0; i <= 5; ++i)
		{
			iPos = strFileName.rfind(strType[i]);
			if (iPos != strFileName.npos)
			{
				return 0;
			}
		}
	}
	return -1;
}

// 在指定路径下删除DelFileType指定类型的文件， 
// vctFileDataInfo 文件信息数组 ； 
void DelFiles(vector<string>& vctFileDataInfo, const string& strPath)
{
	vector<string>::iterator iter;
	string strTempPath;
	string strTemp;
	char szDelPath[256];
	int iIsDel = 0;
	int iDelLength = strPath.length();
	for (iter = vctFileDataInfo.begin(); iter != vctFileDataInfo.end(); ++iter)
	{
		strTempPath = *iter;
		strTemp.assign(strTempPath).erase(0, iDelLength);
		iIsDel = FileNameCompare(strTemp,1);
		if (iIsDel == 0)
		{
			strTempPath.insert(0, "del ");
			strTempPath.append(" /s /q");
			strcpy_s(szDelPath, strTempPath.c_str());
			std::cout << strTempPath << std::endl;
			system(strTempPath.c_str());
		}
	}
}

// 在指定路径下删除DelFileType指定类型的文件夹， 
// vctFileFolderInfo的文件信息 ； 
void DelFolders(vector<string>& vctFileFolderInfo, const string& strPath)
{
	vector<string>::iterator iter;
	string strTempPath;
	string strTemp;
	char szDelPath[256] = { "/0" };
	int iDelLength = strPath.length();
	int iRes = 0;
	for (iter = vctFileFolderInfo.begin(); iter < vctFileFolderInfo.end(); ++iter)
	{
		strTempPath = *iter;
		strTemp.assign(strTempPath).erase(0, iDelLength);
		iRes = FileNameCompare(strTemp,2);
		if (iRes == 0)
		{
			strTempPath.insert(0, "rmdir ");
			strTempPath.append(" /s /q");
			strcpy_s(szDelPath, strTempPath.c_str());
			std::cout << strTempPath << std::endl;
			system(strTempPath.c_str());
		}
	}
}