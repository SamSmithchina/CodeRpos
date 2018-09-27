#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	string strTemp = "111";
	uint64_t ui64Temp1 =10;
	ui64Temp1 += strtoull(strTemp.c_str(), NULL, 10);

	strTemp = "222";
	uint64_t ui64Temp2 = 20;
	ui64Temp2+= strtoull(strTemp.c_str() , NULL, 10);

	cout<<"ui64Temp1 = "<< ui64Temp1 << endl
		<<"ui64Temp2 = "<< ui64Temp2 <<endl;

}

/*
ui64Temp1 = 111
ui64Temp2 = 222
*/
