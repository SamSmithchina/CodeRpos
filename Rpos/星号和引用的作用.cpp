#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	//星号 指针
	char *ptrA =NULL;
	char szBuffer[20] =  {"hello,world"};
	ptrA = szBuffer ;
	cout <<  "ptrA = szBuffer+0 , szBuffer[] = " << szBuffer << " \t,*ptrA = "<< *ptrA <<std::endl;
	printf( "ptrC地址 = %x, szBuffer 地址 = %x \n\n", ptrA,szBuffer);

	//引号指针引用
	char szObject = 'O';
	char &szQuot = szObject;
	char* ptrB = & szQuot;
	cout <<  "char &szQuot = char szObject = 'O'; \t szQuot = " << szQuot
	     <<  "\tchar* ptrB = & szQuot;  *ptrB = " << *ptrB <<std::endl;
	printf("cahr* ptrB = & szQuot;  ptrB 地址 = %x , szQuot 地址 = %x ， szObject 地址 = %x \n\n",ptrB,&szQuot, & szObject);
	//更改引用的值
	szQuot = 'W';
	cout <<  "szQuot = 'W'; szObject = " << szObject <<" ;\t  szQuot = " << szQuot 		//这里能够反应，一个非指针变量应用 另一个变量，当前者指针改变，原被引用的变量也会改变；
	     <<" \t *ptrB = " << *ptrB <<std::endl;
	printf("cahr* ptrB = & szQuot;  ptrB 地址 = %x , szQuot 地址 = %x ， szObject 地址 = %x \n\n",ptrB,&szQuot, & szObject);
	//改变指针的值
	*ptrB  = 'K';
	cout <<  "*ptrB  = 'K';; szObject = " << szObject <<" ;\t  szQuot = " << szQuot
	     <<  " \t *ptrB = " << *ptrB <<std::endl;
	printf("cahr* ptrB = & szQuot;  ptrB 地址 = %x , szQuot 地址 = %x ， szObject 地址 = %x \n\n",ptrB,&szQuot, & szObject);

	char szArray[20] = { "123456789"};
	printf("引用&-- 	char szArray[20] = { \"123456789\"}; ,szArray地址 = %x\n" ,szArray+0);
	char * ptrQuot = NULL;
	ptrQuot = szArray;
	*ptrQuot = '2';
	cout << "*ptrQuot = "<< *ptrQuot <<" szArray = " << szArray << endl;
	printf("引用&-- 	ptrQuot = &szQuot; *ptrQuot = %C ,szArray[] = %s ,  ptrQuot地址 = %x\n\n" ,*ptrQuot, szArray , ptrQuot);


	int i = 0x41424344;
	int *pi;
	char *pc;
	pi = &i;
	pc = (char *)pi;
	printf("\n%x\t%x\t%x\t%x\n", pc[0], pc[1], pc[2], pc[3]);
	printf("\n%x\t%x\t%x\t%x\n", pc, pc+1, pc+2, pc+3);

	return 0;
}

/*
ptrA = szBuffer+0 , szBuffer[] = hello,world    ,*ptrA = h
ptrC地址 = 22fde0, szBuffer 地址 = 22fde0

char &szQuot = char szObject = 'O';      szQuot = O     char* ptrB = & szQuot;
*ptrB = O
cahr* ptrB = & szQuot;  ptrB 地址 = 22fddf , szQuot 地址 = 22fddf ， szObject 地
址 = 22fddf

szQuot = 'W'; szObject = W ;      szQuot = W     *ptrB = W
cahr* ptrB = & szQuot;  ptrB 地址 = 22fddf , szQuot 地址 = 22fddf ， szObject 地
址 = 22fddf

*ptrB  = 'K';; szObject = K ;     szQuot = K     *ptrB = K
cahr* ptrB = & szQuot;  ptrB 地址 = 22fddf , szQuot 地址 = 22fddf ， szObject 地
址 = 22fddf

引用&--         char szArray[20] = { "123456789"}; ,szArray地址 = 22fdc0
*ptrQuot = 2 szArray = 223456789
引用&--         ptrQuot = &szQuot; *ptrQuot = 2 ,szArray[] = 223456789 ,  ptrQuo
t地址 = 22fdc0


44      43      42      41

22fdbc  22fdbd  22fdbe  22fdbf

--------------------------------
Process exited after 0.5274 seconds with return value 0
请按任意键继续. . .

*/
