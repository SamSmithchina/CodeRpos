#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	//星号 指针
	char *ptrC =NULL;
	char szBuffer[20] =  {"hello,world"};
	ptrC = szBuffer ;
	cout <<  "szTemp = *ptrC  ,szTemp = " << *ptrC <<std::endl;

	//引号指针引用
	char szObject = 'O';
	char &szQuot = szObject;
	cout <<  "char &szQuot = szObject;  szQuot = " << szQuot <<std::endl;
	ptrC = & szQuot;
	cout <<  "ptrC = & szQuot;  *ptrC = " << *ptrC <<std::endl;

	//取地址
	printf( "引用&-- 	ptrC = & szQuot;         地址ptrC    = %x\n" , ptrC);
	//不明白
	ptrC = NULL;
	ptrC =  &szObject;
	printf("引用&-- 	char szObject = 'O';     szObject地址 = %x\n " , ptrC);
	ptrC = NULL;
	ptrC = &szQuot;
	printf("引用&-- 	char &szQuot = szObject;  ,szQuot地址 = %x\n" ,ptrC);

	char szArray[20] = { "123456789"};
	printf("引用&-- 	char szArray[20] = { \"123456789\"}; ,szArray地址 = %x\n" ,szArray+0);
	char * ptrQuot = NULL;
	ptrQuot = &szQuot+0;
	*ptrQuot = '2';
	cout << "*ptrQuot = "<< *ptrQuot <<" szArray = " << szArray << endl;
	printf("引用&-- 	ptrQuot = &szQuot; ,ptrQuot地址 = %x\n" ,ptrQuot);


	int i = 0x41424344;
	int *pi;
	char *pc;
	pi = &i;
	pc = (char *)pi;
	printf("\n%x\t%x\t%x\t%x\n", pc[0], pc[1], pc[2], pc[3]);
	printf("\n%x\t%x\t%x\t%x\n", pc+0, pc+1, pc+2, pc+3);

	return 0;
}
