
#include "head.h"
//extern char chextern[];
extern char chextern[];
extern int i;

void fun1()
{
	// char chextern[] = "87654321";
	chextern[0] = '9';
	++i;
	cout << "chextern" << chextern << endl;
	cout << "fun1()" << i << endl;
	//cout << "chstatic" << chstatic << endl;

}
