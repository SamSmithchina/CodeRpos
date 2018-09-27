#include <iostream>
#include <string>

#include <stdlib.h>


using namespace std;

int main()
{
	string str ="123.321";
	double d =0;
	d =atof(str.c_str());
	cout<<d<<endl;
	return 0;
}
