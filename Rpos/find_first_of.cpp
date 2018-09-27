#include <iostream>
#include <string>

using namespace std;

int main()
{
	string strTemp = "ABCD";
	int iPos = 0;
	
	iPos =strTemp.find_first_of('E', 0);
	cout << " if  string  do not exist  a world, string.find_first_of such world will return : " << iPos << endl;   // return -1;
	strTemp = "EEEEEE";
	iPos = strTemp.find_first_not_of( 'E', 0);
	cout<< " if string makeup by a world ,str.find_first_no _of such world  will return : " << iPos << endl;  //return -1;
}
