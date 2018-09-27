/******************************************************************
* Author:
* Function:
* Time: 2018-06-04 16:59:59
* Description:
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/

#include<iostream>
#include<stdlib.h>

using namespace std;

class myclass
{
public :
    double d;
    int i;
};

int main()
{
    double *ptr = NULL;
    double d =0;
    int   i=0;
    //myclass myc;

    cout<<"int size = "<<sizeof(i)<<endl;
    cout<<"double ptr size = "<<sizeof(ptr)<<endl;

    cout<<"double size = "<<sizeof(d)<<endl;

    cout<<"class size = "<<sizeof(myclass)<<endl;

    return 0;
}
