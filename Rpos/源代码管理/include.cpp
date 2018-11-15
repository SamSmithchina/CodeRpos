#include "include.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

//string* WideCharToString(const wchar_t wcTemp)
//{
//
//}



//wchar_t StringToWideChar(const string strTemp)
//{
//	
//}


char* WideCharToChar(const wchar_t* wcTemp)
{
	int iSize = WideCharToMultiByte(CP_OEMCP, 0, wcTemp, wcslen(wcTemp), NULL, 0, NULL, NULL);
	char* cPtrTemp = NULL;
	try
	{
		cPtrTemp = new char[iSize];
	}
	catch (exception& e)
	{
		throw(e.what());
	}

	if (NULL == cPtrTemp)
	{
		cerr << "new a memory failed! " << endl;
	}
	WideCharToMultiByte(CP_OEMCP, 0, wcTemp, wcslen(wcTemp), cPtrTemp, iSize, NULL, NULL);
	cPtrTemp[iSize] = '\0';

	return cPtrTemp;
}

wchar_t* CharTOWideChar(const char* cTemp)
{
	wchar_t* wcTemp = NULL;
	try
	{
		int iSize = MultiByteToWideChar(CP_OEMCP, 0, cTemp, strlen(cTemp) + 1, NULL, 0);
		wcTemp = new wchar_t[iSize];

		MultiByteToWideChar(CP_OEMCP, 0, cTemp, strlen(cTemp) + 1, wcTemp, iSize);
	}
	catch (exception& e)
	{
		throw(e.what());
	}

	if (NULL == wcTemp)
	{
		cerr << "new a memory failed!" << "\n please check the program carefally !" << endl;
	}
	return wcTemp;
}



/*
#define _wfinddata_t    _wfinddata64i32_t
struct _wfinddata32_t {
unsigned    attrib;			// _A_ARCH（存档）、 _A_HIDDEN（隐藏）、_A_NORMAL（正常）、_A_RDONLY（只读）、_A_SUBDIR（文件夹）、_A_SYSTEM（系统），属性可组合
__time32_t  time_create;    // -1 for FAT file systems
__time32_t  time_access;    // -1 for FAT file systems
__time32_t  time_write;
_fsize_t    size;
wchar_t     name[260];
};
*/

// 获取strPath路径下所有文件的属性（用结构体_wfindData_t 存储）
// 2018年9月27日 这个代码块有问题，我写的功能没有实现，但不清楚这几个函数_wfindfirst64()_wfindnext64()的运作，
// 参考 https://blog.csdn.net/liuxyen/article/details/53580747 ，编写GetAllFiles()实现这个模块功能
// parameter: strPath 指定的路径；
// outpat : vector<_wfinddata_t> 文件列表（子文件夹会递归包含下层子文件夹），
//          不区分文件层次关系，
void  GetFilesAttributes(const string& strPath, vector<string>& vctFileDataInfo)
{
	long lHFile = 0; //文件句柄

	//
	string strFileName;
	string strTemp;
	_wfinddata64_t filedataInfo; //文件信息
	strTemp = strPath;
	//strTemp.append("\\*");
	wchar_t* wcPath = CharTOWideChar(strTemp.c_str());

	//主要处理过程
	if ((lHFile = _wfindfirst64(wcPath, &filedataInfo)) != -1)
	{
		do
		{
			if (filedataInfo.attrib & _A_SUBDIR)	//if it's a sub directory
			{
				if (strFileName.compare(".") != 0 && strFileName.compare("..") != 0)
				{
					strTemp = strPath;
					strTemp.append("\\");
					strFileName = WideCharToChar(filedataInfo.name);
					strTemp = strTemp.append(strFileName);
					vctFileDataInfo.push_back(strTemp);
					GetFilesAttributes(strTemp, vctFileDataInfo);
				}
			}
			else
			{
				strTemp = strPath;
				strTemp.append("\\");
				strFileName = WideCharToChar(filedataInfo.name);
				strTemp = strTemp.append(strFileName);
				vctFileDataInfo.push_back(strTemp);
			}
		} while (_wfindnext64(lHFile, &filedataInfo));

	}
	else
	{
		cerr << strPath << "\t doesn't exist any file" << endl;
	}
	_findclose(lHFile);
}

// 参考 https://blog.csdn.net/liuxyen/article/details/53580747 ，编写GetAllFiles()实现这个模块功能
// 通过修改都{。。。}while 循环中if（）语句，可以达到查找当前目录下非子文件夹的文件；查找所有文件夹， 
// 或者在查找结果是加以判断选出特定的文件
void GetAllFiles(const string& strPath,
	vector<string>& vctFileDataInfo,
	vector<string>& vctFileFolderInfo,
	const string& strFormat = "")
{
	std::cout << strPath << std::endl;
	long lFile = 0;
	//文件信息    
	struct _finddata_t fileInfo;//用来存储文件信息的结构体    
	string strPathTemp;
	if ((lFile = _findfirst(strPathTemp.assign(strPath).append("\\*").append(strFormat).c_str(), &fileInfo)) != -1)
	{
		do
		{
			if ((fileInfo.attrib & _A_SUBDIR)) //如果查找到的是文件夹  
			{
				if (strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0) //进入文件夹查找  
				{
					vctFileFolderInfo.push_back(strPathTemp.assign(strPath).append("\\").append(fileInfo.name)); //把文件夹名存入vector
					GetAllFiles(strPathTemp.assign(strPath).append("\\").append(fileInfo.name), vctFileDataInfo,vctFileFolderInfo, strFormat);
				}
			}
			else//如果查找到的不是是文件夹   
			{
				vctFileDataInfo.push_back(strPathTemp.assign(strPath).append("\\").append(fileInfo.name));
				//将文件路径保存，也可以只保存文件名:   p.assign(fileInfo.name)
			}
		} while (_findnext(lFile, &fileInfo) == 0);
	}//end if

	_findclose(lFile); //关闭由FindFirstFile函数创建的一个搜索句柄 
}

// 打印文件列表
void DispayFileList(vector<string>& vctFileDataInfo)
{
	vector<string>::iterator itr;
	for (itr = vctFileDataInfo.begin(); itr != vctFileDataInfo.end(); ++itr)
	{
		cout << *itr << endl;
	}

}


//定义一个hash函数 ，将字符串转换为1个整数 
// https://blog.csdn.net/yozidream/article/details/22789147#
hash_t hash_(char const* str)
{
	hash_t ret{ basis };

	while (*str){
		ret ^= *str;
		ret *= prime;
		str++;
	}

	return ret;
}

//利用c++11自定义文字常量的语法，定义一个constexpr函数，switch的case标签处调用这个constexpr函数
const hash_t hash_compile_time(char const* str, const hash_t last_value = basis)
{
	return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}

//constexpr unsigned long long operator _ _hash(char const* p, size_t)
//{
//	return hash_compile_time(p);
//}

#define TYPE(x) (##x)
// 统计不同类型的文件个数， 记录总的文件个数
void CalcuFileTypes( vector<string>& vctFileDataInfo)
{
	vector<string>::iterator itr;
	string strFileType;
	string strFileName;
	FileType emFileType;
	int *iArr = NULL;
	int iTypeNum = 6;
	int iTotal = 0;
	int i = 0;

	try
	{
		iArr = new int[iTypeNum];
		memset(iArr, 0, sizeof(int) * iTypeNum);
		for (i; i < iTypeNum; i++)
		{
			iArr[i] = 0;
		}
	}
	catch (exception& e)
	{
		throw(e.what());
	}
	if (iArr == NULL)
	{
		cerr << "开辟空间失败" << endl;
		exit(-1);
	}

	for (itr = vctFileDataInfo.begin(); itr != vctFileDataInfo.end(); ++itr)
	{
		//所有文件以点'.'加类型后缀区分文件类型
		strFileName = *itr;
		strFileType = strFileName.substr(strFileName.find_first_of(".") + 1, strFileName.length() - 1);

		//enum FileType { cpp, c, h, md, txt , other };
		if (strFileType.compare("cpp") == 0)
		{
			emFileType = FileType::cpp;
		}
		else if (strFileType.compare("c") == 0)
		{
			emFileType = FileType::c;
		}
		else if (strFileType.compare("h") == 0)
		{
			emFileType = FileType::h;
		}
		else if (strFileType.compare("md") == 0)
		{
			emFileType = FileType::md;
		}
		else if (strFileType.compare("txt") == 0)
		{
			emFileType = FileType::txt;
		}
		else
		{
	//		cout << strFileName << endl;
			emFileType = FileType::other;
		}
		iArr[emFileType]++;
		iTotal++;
	}

	cout << "总文件个数 ： " << iTotal << endl;
	for (i = 0; i < iTypeNum; i++)
	{
		switch (i)
		{
		case FileType::cpp:
			cout << "FileType::cpp" << " 数量 ： " << iArr[FileType::cpp] << endl;
			break;
		case FileType::c:
			cout << "FileType::c" << " 数量 ： " << iArr[FileType::c] << endl;
			break;
		case FileType::h:
			cout << "FileType::h" << " 数量 ： " << iArr[FileType::h] << endl;
			break;
		case FileType::md:
			cout << "FileType::md" << " 数量 ： " << iArr[FileType::md] << endl;
			break;
		case FileType::txt:
			cout << "FileType::txt" << " 数量 ： " << iArr[FileType::txt] << endl;
			break;
		default:
			cout << "FileType::other" << " 数量 ： " << iArr[FileType::other] << endl;
		}
	}
	delete[] iArr;
}