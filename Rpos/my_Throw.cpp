#include<iostream>
#include<stdlib.h>
//#include<> 
 using namespace std;
 
void CompareChar(char , char); 

int main()
{
	char a = 'a',b = 'b';
	try
	{
		CompareChar('w','k'); 
	}
	catch(const char *ch )
	{
		cout<<ch<<endl;
		cerr <<"cerr"<<endl;
	}

	//system("clr");
	return 0;
}


void CompareChar(char a, char b)
{
	if ( a == b )
		throw "a and b are equal !";
	else if(a > b)
		throw " a is gigger than b !";
	else if(a < b)
		throw "a is smaller than b !";
}
