/******************************************************************
* Author:	Sam Smith
* Function:
* Time:
* Description:
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>
//#include <math.h>
//#include <iomanip>

using namespace std;

int main(int argc, char* argv[])
{
    HANDLE m_hMutex = CreateMutex(NULL,TRUE,"cplusplus_me");
    DWORD dwRet = GetLastError();
    if (m_hMutex)
    {
        if (ERROR_ALREADY_EXISTS == dwRet)
        {
            cout<<"程序已经在运行中了,程序退出!\n"<<endl;
            CloseHandle(m_hMutex);
            return 0;
        }
    }
    else
    {
        cout<<"创建互斥量错误,程序退出!\n"<<endl;
        CloseHandle(m_hMutex);
        return 0;
    }
    int i =0;
    while(i++<3)
    {
        cout<<"cplusplus_me\n"<<endl;
    }
    CloseHandle(m_hMutex);
    return 0;
}
