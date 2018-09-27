/******************************************************************
* Author:	Sam Smith
* Function: ¼ìÑé string .erase  ºÍ string . find_first_of() º¯Êý
* Time:      2018-07-12 15:52:03
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
    string str = "123456789.00";
    int pos =0;

    pos = str.find_first_of(" ");
    cout<< pos<<endl;
    pos = str.find_first_of (" 3");
    cout<<pos <<endl;
    pos = str.find_first_not_of("3");
    cout <<pos <<endl;


    return 0;
}
