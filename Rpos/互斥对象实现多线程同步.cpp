
#include <windows.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
 
 
DWORD WINAPI MyThreadProc1(LPVOID lpParameter);
DWORD WINAPI MyThreadProc2(LPVOID lpParameter);
DWORD WINAPI MyThreadProc3(LPVOID lpParameter);
 
int index = 100;
HANDLE hMutex;
 
int main()
{
    HANDLE handle1,handle2,handle3;
    handle1 = CreateThread(NULL,0,MyThreadProc1,NULL,0,NULL);
    handle2 = CreateThread(NULL,0,MyThreadProc2,NULL,0,NULL);
    handle3 = CreateThread(NULL,0,MyThreadProc3,NULL,0,NULL);
 
    if(NULL == handle1)
    {
        cout<<"Create Thread failed !"<<endl;
        return -1;
    }
    if(NULL == handle2)
    {
        cout<<"Create Thread failed !"<<endl;
        return -1;
    }
    if(NULL == handle3)
    {
        cout<<"Create Thread failed !"<<endl;
        return -1;
    }
 
    CloseHandle(handle1);
    CloseHandle(handle2);
    CloseHandle(handle3);
 
    hMutex = CreateMutex(NULL,TRUE,NULL);
 
    Sleep(2000);
    system("PAUSE");
    return 0;
}
DWORD WINAPI MyThreadProc1(LPVOID lpParameter)
{
    while(true)
    {
        WaitForSingleObject(hMutex,INFINITE);
        if(index > 0)
        {
           // Sleep(1);
            cout<<"The Index1 Number is : "<<index--<<endl;
        }
        else
            break;
    }
    return 0;
}
DWORD WINAPI MyThreadProc2(LPVOID lpParameter)
{
    while(true)
    {
        WaitForSingleObject(hMutex,INFINITE);
        if(index > 0)
        {
           // Sleep(1);
            cout<<"The Index2 Number is : "<<index--<<endl;
        }
        else
            break;
    }
    return 0;
}
 
DWORD WINAPI MyThreadProc3(LPVOID lpParameter)
{
    while(true)
    {
        WaitForSingleObject(hMutex,INFINITE);
        if(index > 0)
        {
          //  Sleep(1);
            cout<<"The Index3 Number is : "<<index--<<endl;
        }
        else
            break;
    }
    return 0;
}
