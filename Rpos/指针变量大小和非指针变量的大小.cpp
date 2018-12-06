#include <iostream>
using namespace std;

int main() {
	char *szTemp = NULL;
	int *iTemp =NULL;
	double *dTemp = NULL;
	cout << "sizeof(*char) = " <<  sizeof(szTemp) << endl;
	cout << "sizeof(char) = " << sizeof(*szTemp) << endl;

	cout << "sizeof(*int) = " <<  sizeof(iTemp) << endl;
	cout << "sizeof(int) = " << sizeof(*iTemp) << endl;
	
	cout << "sizeof(*double) = " <<  sizeof(dTemp) << endl;
	cout << "sizeof(double) = " << sizeof(*dTemp) << endl;

	return 0;
}

/*
执行结果：
sizeof(*char) = 8
sizeof(char) = 1
sizeof(*int) = 8
sizeof(int) = 4
sizeof(*double) = 8
sizeof(double) = 8

--------------------------------
Process exited after 0.3255 seconds with return value 0
请按任意键继续. . .
*/
