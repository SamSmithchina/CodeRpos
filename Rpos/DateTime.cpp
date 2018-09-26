/******************************************************************
* Author:	Sam Smith
* Function: 获取现在的时间time和日期 date
* Time: 2018-06-25 10:51:36
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
#include <time.h>
//#include <math.h>
//#include <iomanip>

using namespace std;

int main()
{
    //example 1
    time_t now;
    time(&now); //获取时间
    char chdate[9] ={"1"};
    char chtime[9] = {"1"};
    strftime(chdate, 9, "%Y%m%d", localtime(&now));	//char 8
    strftime(chtime, 9, "%H:%M:%S", localtime(&now));	//char 8
    cout<< chtime[8] <<endl;
    cout<<chdate<<endl<<chtime<<endl;

    //example 2
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    strftime (buffer,80,"this is: %Y%m%d %H:%M:%S",timeinfo);
    cout<<buffer;

	//example3
	tm tmPtr;
	time_t tNow;
	time(&tNow);
	char szTime[20] = { "\0" };
	string strTemp;
	try
	{
		localtime_s(&tmPtr, &tNow);
		_Strftime(szTime, 13, "%Y:%m:%d", &tmPtr, NULL);
		strTemp += szTime;
		_Strftime(szTime, 9, "%H:%S:M", &tmPtr, NULL);
		strTemp += "  ";
		strTemp += szTime;
	}
	
    return 0;
}
