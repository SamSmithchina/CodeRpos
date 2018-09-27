/*
  double 是4 字节数据， 取 每个字节的地址和该字节上存储的二进制数据
  移位操作 >>
*/

#include <iostream>

#include <stdlib.h>

using namespace std;


int main()
{
	double d = 0.0;
	
	int a = 0x41424344;
	int iMove = (a >> 8);
	
	// 左移 右移 https://blog.csdn.net/tangyanzhi1111/article/details/21696943	//每左移一位 数据 x2； 
	cout << "a = " << a << endl;
	cout << "右移 8 位 a = " << a << endl;

	iMove = a >> 16;
	cout << "右移 16 位 a = " << a << endl;

	iMove = a >> 24;
	cout << "右移 16 位 a = " << a << endl;

	iMove = a << 8;
	cout << "左移 16 位 a = " << a << endl;

	iMove =a << 16;
	cout << "左移 8 位 a = " << a << endl;		

	//取数据地址
	a = 0x414243444;
	int *iLocal = &a;
	cout << "取 a 的地址 = " << iLocal << endl;

	//取数据字节大小
	int size = sizeof(int);
	cout << "sizeof(int) =  " << size << endl;

	//取每个字节上的数据
	char *ptrCh = (char *)iLocal;
	for (int i = 1; i <= size; i++)
	{
		iLocal = (int *)ptrCh;
		cout << " i = "<<i	
			<<"\t地址 : "<<iLocal 
			<<"\t数据 : "<< *ptrCh << endl<<endl;
		ptrCh += 1;
	}

	int i = 0x41424344;
	int *pi;
	char *pc;
	pi = &i;
	pc = (char *)pi;
	printf("\n%x\t%x\t%x\t%x\n", pc[0], pc[1], pc[2], pc[3]);

	system("pause");
	return 0;
}