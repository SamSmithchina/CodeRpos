#ifndef __IGNORE_H__
#define __IGNORE_H__

#include <string>
#include <iostream>
#include <vector>

using namespace std;

//�Ƚϵ�ǰ�ļ��Ƿ���ָ����ɾ�����ļ����ͣ�
// input��  ��ǰ�ļ�����strFilename�� int iFileOrFolder �ļ�=1  �ļ��� =2
// output�� ��ָ���ļ�����0��        ���Ƿ���-1��
int FileNameCompare(const string& strFileName, int iFileOrFolder);

// ��ָ��·����ɾ��DelFileTypeָ�����͵��ļ��� 
// vctFileDataInfo ���ļ���Ϣ �� 
void DelFiles(vector<string>& vctFileDataInfo, const string& strPath);

// ��ָ��·����ɾ��DelFileTypeָ�����͵��ļ��У� 
// vctFileFolderInfo���ļ���Ϣ �� 
void DelFolders(vector<string>& vctFileFolderInfo, const string& strPath);
#endif