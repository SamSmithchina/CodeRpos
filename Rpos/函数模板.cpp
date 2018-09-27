/******************************************************************
* Author:sam smith
* Function: 函数模板
* Time:2018-05-28 15:23:28
* Description:
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/

#include<iostream>
#include<windows.h>
using namespace std;

#define MAX(x,y) ((x) > (y)?(x):(y))


void MAX_int(int x,int y)
{
    cout<<MAX(x,y)<<endl;
}

void MAX_double(double x,double y)
{

    cout<<MAX(x,y)<<endl;
}

void MAX_float(float x,float y)
{
    cout<<MAX(x,y)<<endl;

}

int main()
{
    MAX_int(1, 2);

    MAX_double((1.1),(double)(1.2));

    MAX_float((float)(4.4),(float)( 3.3));

    return 0;
}
