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
	 �Ƽ������·������õ���ǰ��������Ŀ¼�Ƚϰ�ȫ��
	 void _splitpath( const char *path, char *drive, char *dir, char *fname, char *ext );
	 �������ֽ⿪ʼ�ᵽ��_pgmptr��Ȼ������
	 void _makepath( char *path, const char *drive, const char *dir, const char *fname, const char *ext );
	 �������Էֽ���·��������ϡ����������������������ǿ��ʹ����
	 ���������е��й�Ŀ¼��·������Ĳ��������Ը㶨��
	 */
	//system("echo %cd%"); //��ʾ��ǰ·��
	char szPath[256] = { "\0" };
	int n = GetModuleFileNameA(NULL, szPath, 256);
	(strrchr(szPath, '\\'))[0] = 0; // ɾ���ļ�����ֻ���·���ִ�  
	string strPath = szPath; //��������·��
	//strPath = "E:\\ProgramWorkstation\\Rpository\\Rpos";
	vector<string> vctFileDataInfo;
	vector<string> vctFileFolderInfo;
	vctFileDataInfo.clear();

	string strFormat = "";
	GetAllFiles(strPath, vctFileDataInfo, vctFileFolderInfo, strFormat);

	std::cout << std::endl
		<< "----------------------------------------------" << std::endl
		<< "----------------------------------------------" << std::endl
		<< " ��ǰ·���������ļ���" << std::endl << std::endl;
	DispayFileList(vctFileDataInfo);

	//GetFilesAttributes(strPath, vctFileDataInfo);
	CalcuFileTypes(vctFileDataInfo);

	std::cout
		<< "----------------------------------------------" << std::endl
		<< "----------------------------------------------" << std::endl
		<< " ָ��ɾ���ļ����ͣ�" << std::endl
		<< " Debug\\, log\\,  bin\\, x64\\, lib\\, *.tlog\\" << std::endl
		<< " *.sln, *.sdf, *.opensdf, *.suo, *.vcxproj, *.filters"
		<< std::endl << std::endl;
	DelFolders(vctFileFolderInfo, strPath);
	DelFiles(vctFileDataInfo, strPath);

	system("pause");
	return 0;
}