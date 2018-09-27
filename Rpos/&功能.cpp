/******************************************************************
* Author:Sam Smith
* Function:
* Time:  2018-06-06 13:16:40
* Description:  &  取变量地址
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>
#include <string>
#include <iomanip>

void func(int &i)
{
    i=999;
    std::cout<<" & i ="<<i<<std::endl;

}

int main()
{
    int  i =1010;

    std::cout<<"i : =" <<i<<std::endl;

    func(i);

    std::cout<<"i : =" <<i<<std::endl;



    return 0;
}
