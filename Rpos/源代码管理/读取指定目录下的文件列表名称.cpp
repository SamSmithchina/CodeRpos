//参考链接 ：https://www.cnblogs.com/tgyf/p/3839894.html
//功能说明 ：为了统计这一段时间里写的代码量，我需要设计一个读取工程目录下所有文件（后期改进成指定格式的源代码文件），
//			 进而统计每个文件的代码行数、空行数、注释代码行数，和总行数，总空行数、总注释行数，
//			 这个文件只扫描统计文件属性
//时间 ：2018年9月27日10点39分
#include "wchar_t char.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <tchar.h>
#include <Windows.h>
#include <io.h>

using namespace std;

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
void  GetFilesAttributes(const string strPath, vector<string>& vctFileDataInfo)
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
	if (lHFile = _wfindfirst64(wcPath, &filedataInfo) != -1)
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
void GetAllFiles(const string strPath, vector<string>& vctFileDataInfo, const string strFormat = "")
{

	long hFile = 0;
	//文件信息    
	struct _finddata_t fileinfo;//用来存储文件信息的结构体    
	string p;
	if ((hFile = _findfirst(p.assign(strPath).append("\\*").append(strFormat).c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR)) //如果查找到的是文件夹  
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) //进入文件夹查找  
				{
					//	vctFileDataInfo.push_back(p.assign(strPath).append("\\").append(fileinfo.name)); //把文件夹名存入vector
					GetAllFiles(p.assign(strPath).append("\\").append(fileinfo.name), vctFileDataInfo, strFormat);
				}
			}
			else//如果查找到的不是是文件夹   
			{
				vctFileDataInfo.push_back(p.assign(strPath).append("\\").append(fileinfo.name));
				//将文件路径保存，也可以只保存文件名:   p.assign(fileinfo.name)
			}
		} while (_findnext(hFile, &fileinfo) == 0);
	}//end if
	_findclose(hFile);

}

// 打印文件列表
void DispayFileList(vector<string> vctFileDataInfo)
{
	vector<string>::iterator itr;
	for (itr = vctFileDataInfo.begin(); itr != vctFileDataInfo.end(); itr++)
	{
		cout << *itr << endl;
	}

}

// 定义文件的类型
enum FileType { cpp, c, h, md, txt, other };
typedef unsigned long long  hash_t;
const hash_t prime = 0x100000001B3ull;
const hash_t basis = 0xCBF29CE484222325ull;

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
void CalcuFileTypes(vector<string> vctFileDataInfo)
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
		memset(iArr, 0, sizeof(iArr));
		for (i; i < iTypeNum; i++)
		{
			iArr[i] = 0;
		}
	}
	catch (exception e)
	{
		throw(e.what());
	}
	if (iArr == NULL)
	{
		cerr << "开辟空间失败" << endl;
		exit(-1);
	}

	for (itr = vctFileDataInfo.begin(); itr != vctFileDataInfo.end(); itr++)
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
			cout << strFileName << endl;
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

int main()
{
	string strPath = "f:\\file\\ProjectWorkstation\\CodeBlocksWorkPlace\\Rpos";
	vector<string> vctFileDataInfo;
	vctFileDataInfo.clear();

	string strFormat = "";
	GetAllFiles(strPath, vctFileDataInfo, strFormat);

	//GetFilesAttributes(strPath, vctFileDataInfo);
	CalcuFileTypes(vctFileDataInfo);

	system("pause");
	return 0;
}

/*
总文件个数 ： 131
FileType::cpp 数量 ： 105
FileType::c 数量 ： 1
FileType::h 数量 ： 22
FileType::md 数量 ： 1
FileType::txt 数量 ： 2
FileType::other 数量 ： 0
请按任意键继续. . .
*/