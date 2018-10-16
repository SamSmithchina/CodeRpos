#ifndef __WCHAR_T_CHAR_H__
#define __WCHAR_T_CHAR_H__
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
	catch (exception e)
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
	catch (exception e)
	{
		throw(e.what());
	}

	if (NULL == wcTemp)
	{
		cerr << "new a memory failed!" << "\n please check the program carefally !" << endl;
	}
	return wcTemp;
}

#endif