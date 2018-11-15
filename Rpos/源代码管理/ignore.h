#ifndef __IGNORE_H__
#define __IGNORE_H__

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//比较当前文件是否是指定待删除的文件类型；
// input：  当前文件名称strFilename， int iFileOrFolder 文件=1  文件夹 =2
// output： 是指定文件返回0，        不是返回-1；
int FileNameCompare(const string& strFileName, int iFileOrFolder);

// 在指定路径下删除DelFileType指定类型的文件， 
// vctFileDataInfo 的文件信息 ； 
void DelFiles(vector<string>& vctFileDataInfo, const string& strPath);

// 在指定路径下删除DelFileType指定类型的文件夹， 
// vctFileFolderInfo的文件信息 ； 
void DelFolders(vector<string>& vctFileFolderInfo, const string& strPath);
#endif