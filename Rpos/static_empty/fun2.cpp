
#include "head.h"
//extern char chextern[];
extern char chextern[];
extern int i;

void fun2()
{

	//  cout<<"chstatic "<<chstatic<<endl;
	i++;
	cout << "chextern" << chextern << endl;
	cout << "fun2()" << i << endl;
}
