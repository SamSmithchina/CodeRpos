#ifndef __FILEOPERATORHELPER__
#define __FILEOPARATORHELPER__

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void ReadFile(string strFileName)
{
	ifstream ifPtr;
	string strTemp;
	ifPtr.open(strFileName, ios::in);
	char szTemp[181] = { "\0" };
	while (!ifPtr.eof())
	{
		ifPtr.getline(szTemp,181);
		//ifPtr.read(szTemp, 81);
		cout << szTemp<<endl;
	}

	ifPtr.close();
	std::cout << "\nRead Finish !" << std::endl << std::endl;
}

void WriteFile(string strFileName)
{

	ofstream ofPtr;
	ofPtr.open(strFileName, ios::out | ios::app);
	tm tmPtr;
	time_t tNow;
	time(&tNow);
	char szTime[20] = { "\0" };
	string strTemp;
	try
	{
		localtime_s(&tmPtr, &tNow);
		_Strftime(szTime, 13, "%Y:%m:%d", &tmPtr, NULL);
		strTemp += szTime;
		_Strftime(szTime, 9, "%H:%S:M", &tmPtr, NULL);
		strTemp += "  ";
		strTemp += szTime;
	}
	catch (exception e)
	{
		throw(e);
		//throw new RuntimeException();
	}
	catch (const char *str)
	{
		cerr << "error : " << str << endl;
	}
	ofPtr << "\n";
	ofPtr.write(strTemp.c_str(), sizeof(strTemp));
	ofPtr.close();


	cout << "\nWrite Finish !" <<endl << endl;
}
#endif
