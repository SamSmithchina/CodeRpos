#include "ignore.h"
#include <iostream>
#include <Windows.h>
#include <io.h>			// struct _finddata_t fileinfo;
using namespace std;


//ָ��ɾ���ļ����ͣ� ���д�_folder ��׺��Ϊ�ļ��У�
enum DelFileType
{
	debug_folder, log_folder, bin_folder, x64_folder, lib_folder,
	sln, sdf, opensdf, suo, vcxproj, filters
};

//�Ƚϵ�ǰ�ļ��Ƿ���ָ����ɾ�����ļ����ͣ�
// input��  ��ǰ�ļ�����strFilename�� int iFileOrFolder �ļ�=1  �ļ��� =2
// output�� ��ָ���ļ�����0��        ���Ƿ���-1��
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
			iPos = strFileName.rfind(strType[i]); //�ļ�����
			if (i < 6 && iPos != strFileName.npos)
			{
				return -1;
			}
			if (5 <i && iPos != strFileName.npos)//�����ļ�
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

// ��ָ��·����ɾ��DelFileTypeָ�����͵��ļ��� 
// vctFileDataInfo �ļ���Ϣ���� �� 
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

// ��ָ��·����ɾ��DelFileTypeָ�����͵��ļ��У� 
// vctFileFolderInfo���ļ���Ϣ �� 
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