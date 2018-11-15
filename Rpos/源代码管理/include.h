//参考链接 ：https://www.cnblogs.com/tgyf/p/3839894.html
//功能说明 ：为了统计这一段时间里写的代码量，我需要设计一个读取工程目录下所有文件（后期改进成指定格式的源代码文件），
//			 进而统计每个文件的代码行数、空行数、注释代码行数，和总行数，总空行数、总注释行数，
//			 这个文件只扫描统计文件属性
//时间 ：2018年9月27日10点39分
#ifndef __INCLUDE_H__
#define __INCLUDE_H__

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <tchar.h>
#include <Windows.h>
#include <io.h>

using namespace std;


// 定义文件的类型
enum FileType { cpp, c, h, md, txt, other };
typedef unsigned long long  hash_t;
const hash_t prime = 0x100000001B3ull;
const hash_t basis = 0xCBF29CE484222325ull;


wchar_t* CharTOWideChar(const char* cTemp);


char* WideCharToChar(const wchar_t* wcTemp);


// parameter: strPath 指定的路径；
// outpat : vector<_wfinddata_t> 文件列表（子文件夹会递归包含下层子文件夹），
//          不区分文件层次关系，
void  GetFilesAttributes(const string& strPath, vector<string>& vctFileDataInfo);

void GetAllFiles(const string& strPath,
	vector<string>& vctFileDataInfo, 
	vector<string>& vctFileFolderInfo,
	const string& strFormat);

// 打印文件列表
void DispayFileList(vector<string>& vctFileDataInfo);

//定义一个hash函数 ，将字符串转换为1个整数 
// https://blog.csdn.net/yozidream/article/details/22789147#
hash_t hash_(char const* str);

//利用c++11自定义文字常量的语法，定义一个constexpr函数，switch的case标签处调用这个constexpr函数
const hash_t hash_compile_time(char const* str, const hash_t last_value);


// 统计不同类型的文件个数， 记录总的文件个数
void CalcuFileTypes(vector<string>& vctFileDataInfo);

#endif