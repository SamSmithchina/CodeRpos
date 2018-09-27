/******************************************************************
* Author:	Sam Smith
* Function: C++的异常处理方式 try catch throw
* Time: 2018-06-20 08:46:34
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

int main()
{
    int i =0;
    int k =0;

    try
    {
        k = i/i;
        cout<<"try code block\n";
    }
    catch(exception e2)
    {
        throw(e2.what());
        cout<<"catch code block\n";
    }
    catch(exception e1)
    {
        cout<<"catch code block\n";
    }

    return 0;
}
