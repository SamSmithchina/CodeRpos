/*
//	Author: sam 
//	Date: 2018-07-13 09:08:58 
//	Description: strtoll,  atoll;
	 
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string> 
using namespace std;

int main()
{
	string str = "12.34";
	char ch[]="12.34";
	long llTemp =0;
	
	llTemp = strtoll(str.c_str(),NULL, 10);
	cout<<llTemp<<endl;
	
	llTemp = atoll(ch);
	cout<<llTemp<<endl; 
	
	return 0;
}
