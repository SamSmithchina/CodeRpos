/*
	Name: 
	Copyright: 
	Author: 
	Date: 21/06/18 17:27
	Description: 
*/

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
using namespace std;

int main()
{
	stringstream strStream ;
	string str ="111111111.1000";
	long double d =0;
	cout<<setiosflags(ios::fixed)<<setprecision(4)<<d<<endl; 
	clock_t clockBegin;
	clock_t clockEnd;
	
	clockBegin = clock(); 
	for(int i =0;i<100000;i++)
	{
	  
		strStream.clear();
		strStream << str;
		strStream >> d;
	}
	clockEnd = clock();
	cout<<"stringstream used time : "<<clockEnd - clockBegin <<endl;
	
	clockBegin = clock(); 
	for(int i =0; i< 100000; i++)
	{
		d = atof(str.c_str());
	}
	clockEnd = clock();
	cout<<"atof used time : "<<clockEnd - clockBegin <<endl;
	
	
	return 0;
 } 
 /* atof() 比stringstream 标准流输出更快；
 0.0000
stringstream used time : 569
atof used time : 33

 */
