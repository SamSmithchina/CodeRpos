/*
//	Author:sam smith
//	Date:2018-06-21 09:07:07 
//	Description:string stream : double to string;
	
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	stringstream strStream;
	
	double d =21;
	string  str ="";
	
	strStream.clear();
	strStream << d ;
	strStream >> str;
	str = str + ".000";
	cout<<" str :" <<str<<endl; 
	
	return 0;
}
