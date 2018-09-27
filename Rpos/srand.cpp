/******************************************************************
* Author:
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
#include <time.h>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    int i = 0;
	int j = 0;
 
	srand(time(0));
	for(j =0; j<2 ; j++)	
	{
	
    	for(i =1; i<= 20 ; i++)
    	{	
    
        	cout<<rand()%10<<"\t";
        	if(i % 10 == 0)
        	    cout<<endl;
    	}
	}
    return 0;
}
