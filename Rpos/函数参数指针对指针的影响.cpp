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
#include <math.h>
#include <string>
#include <iomanip>

using namespace std;

char* func(char *ch)
{
//    char *c = ch;
    char c1 = 'd';
    char *cc = &c1; 
  //  *c = '2';
	
	ch= cc;

    return ch;
}

int main()
{
    char sce = '0';
    char *ch=&sce;
    //ch = &sce;
    cout<<strlen(ch)<<endl;
    cout<<*ch<<endl;

    ch = func(ch);
    cout<<"func(): "<< *ch <<endl;

    return 0;
}
