#include <iostream>

using namespace std;

int MyFunc1(int iParam1, int iParam2)
{
	return (iParam1 > iParam2 ? iParam1 : iParam2);
}

double MyFunc2(double dParam1, double dParam2)
{
	return(dParam1 > dParam2 ? dParam1 : dParam2);
}

int(*SingleFuncPtr)(int, int); //º¯ÊýÖ¸Õý

template<typename T>
T MyFun(T(*PtrFuncParam)(T t1, T t2), T tParam1, T tParam2)
{
	return PtrFuncParam( tParam1,  tParam2);
}

int main()
{
	int iParam1 = 1, iParam2 = 2;
	double dParam1 = 1.00, dParam2 = 3.45;

 
	SingleFuncPtr = MyFunc1;
	cout << SingleFuncPtr(iParam1, iParam2) << endl;

	
	cout << MyFun(MyFunc1, iParam1, iParam2) <<endl;
	
	cout << MyFun(MyFunc2, dParam1, dParam2) <<endl;

	system("pause");
}
