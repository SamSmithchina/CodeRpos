/******************************************************************
* Author:	Sam Smith
* Function:
* Time:         2018-06-11 17:18:04
* Description:
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

using namespace std;

class MyClassSizeTest
{
public:
    char a;
    char b;
private:
    char c;
    char d;
};



int main()
{
    MyClassSizeTest *ptr = NULL;

	cout << "Sizeof(int) = "<< sizeof(char)  <<endl;
    cout<<"sizeof(ptr) = "<<sizeof(ptr)<<endl;

    ptr = new(MyClassSizeTest);
    cout<<"sizeof(MyClassSizeTest) = "<<sizeof(MyClassSizeTest)<<endl;

	free(ptr);
    return 0;
}
