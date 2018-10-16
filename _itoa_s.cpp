#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int main()
{
	int i = 999;
	char szTemp[17] = {"\0"};
	string strTemp;
	_itoa_s(i , szTemp , 17, 10);
	strTemp = szTemp;
	cout <<"i = "<< i <<"   _itoa_s(i) = " << strTemp << endl;
	return 0;
}

