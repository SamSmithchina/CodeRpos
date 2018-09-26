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

//C++ 乘以小数和除以小数， 编译链接程序都能通过；
int main()
{

    int i =100;
    i  = i*0.01;
    cout<<i<<endl;

    i = 1000;
    i = i / 10000;
    cout<<i<<endl;

    return 0;
}
