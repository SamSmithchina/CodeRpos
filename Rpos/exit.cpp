		#include <iostream>
using namespace std;

void ExitTest(int i )
{
	if(7 < i)					//程序执行到i=8 ，就会终止，之后的循环都不会执行； 
	{
		exit(0); 	
	}
	else
	{
		cout << "i = " << i <<endl;
	}
}

int main()
{
	int i =0;
	for( i =0; i<10; i++)
	{
		ExitTest (i);
	}
	return 0;
}
