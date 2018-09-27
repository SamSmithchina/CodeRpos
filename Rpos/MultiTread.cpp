/******************************************************************
*
* Author：Sam Smith   wangbingzong@szkindom.com
* Time：2018-05-25 16:05:19
* Version：V ...
* Description：
*
* Editor：
* Time：
* Modification：
*
* ********************************************************************
* Copyright (c) $year$ ShenZhen Kindom Cor., Ltd. All rights reserved.
* *******************************************************************/

/******************************************************************
* Function:
* Description:
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/


#include<iostream>
#include<windows.h>
#include<process.h>
using namespace std;






//并行
//_beginthreadex() 创建进程
int ITEM = 100;

unsigned int _stdcall SubThread1(PVOID lpParamter)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "\nID : " << GetCurrentThreadId();

		cout << "\nSubThread1: " << --ITEM << endl;
	}
	return 0L;
}

unsigned int _stdcall SubThread2(PVOID lpParamter)
{
	for (int i = 0; i < 10; i++)
	{
		cout << "\nID : " << GetCurrentThreadId();
		cout << "SubThread2 : " << --ITEM << endl;
	
	}
	return 0L;
}

int  main()
{
	HANDLE hThread1 =(HANDLE) _beginthreadex(NULL, 0, SubThread1, NULL, 0, NULL);

	HANDLE hThread2 =(HANDLE) _beginthreadex(NULL, 0, SubThread2, NULL, 0, NULL);
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	system("pause");
	return 0;
}


//并发，交替执行，使用互斥量Mutex，互斥使用
//CreateThread() 创建进程
//sample example for multiThread
/*
HANDLE hMutex = NULL;
DWORD WINAPI Fun(LPVOID lpParamter)
{
for (int i = 0; i < 10; i++)
{
WaitForSingleObject(hMutex, INFINITE);

cout << "------" << "sub thread : " << i << endl;

ReleaseMutex(hMutex);
}
cout << "sub thread is  end" << endl;


return 0L;
}


int main()
{
//CreadeHandle();
HANDLE hTread = CreateThread(NULL, 0, Fun, NULL, 0, NULL);
hMutex = CreateMutex(NULL, FALSE, "screen"); //loca

//closeHandle()//https://blog.csdn.net/lhsxsh/article/details/3905505
CloseHandle(hTread);

for (int mainI = 0; mainI < 10; mainI++)
{
WaitForSingleObject(hMutex, INFINITE);
cout << "parent : " << mainI << endl;
//Sleep();
//	Sleep(100);
ReleaseMutex(hMutex);
}

system("pause");
return 0;
}
*/