/******************************************************************
* Author:	Sam Smith
* Function:
* Time: 2018-06-12 17:48:27
* Description: 标准错误输出
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
//#include <math.h>
#include <string>
//#include <iomanip>

using namespace std;

int main()
{
    string strError;
    int i =0;
    try
    {
        strError = ("test strerr is working in right way\n");
        i = i/i;
    }
    catch(exception e)
    {
        perror(strError.c_str());
        throw(e);
    }


    return 0;
}
