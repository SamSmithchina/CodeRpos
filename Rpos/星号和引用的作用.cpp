#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	//�Ǻ� ָ��
	char *ptrA =NULL;
	char szBuffer[20] =  {"hello,world"};
	ptrA = szBuffer ;
	cout <<  "ptrA = szBuffer+0 , szBuffer[] = " << szBuffer << " \t,*ptrA = "<< *ptrA <<std::endl;
	printf( "ptrC��ַ = %x, szBuffer ��ַ = %x \n\n", ptrA,szBuffer);

	//����ָ������
	char szObject = 'O';
	char &szQuot = szObject;
	char* ptrB = & szQuot;
	cout <<  "char &szQuot = char szObject = 'O'; \t szQuot = " << szQuot
	     <<  "\tchar* ptrB = & szQuot;  *ptrB = " << *ptrB <<std::endl;
	printf("cahr* ptrB = & szQuot;  ptrB ��ַ = %x , szQuot ��ַ = %x �� szObject ��ַ = %x \n\n",ptrB,&szQuot, & szObject);
	//�������õ�ֵ
	szQuot = 'W';
	cout <<  "szQuot = 'W'; szObject = " << szObject <<" ;\t  szQuot = " << szQuot 		//�����ܹ���Ӧ��һ����ָ�����Ӧ�� ��һ����������ǰ��ָ��ı䣬ԭ�����õı���Ҳ��ı䣻
	     <<" \t *ptrB = " << *ptrB <<std::endl;
	printf("cahr* ptrB = & szQuot;  ptrB ��ַ = %x , szQuot ��ַ = %x �� szObject ��ַ = %x \n\n",ptrB,&szQuot, & szObject);
	//�ı�ָ���ֵ
	*ptrB  = 'K';
	cout <<  "*ptrB  = 'K';; szObject = " << szObject <<" ;\t  szQuot = " << szQuot
	     <<  " \t *ptrB = " << *ptrB <<std::endl;
	printf("cahr* ptrB = & szQuot;  ptrB ��ַ = %x , szQuot ��ַ = %x �� szObject ��ַ = %x \n\n",ptrB,&szQuot, & szObject);

	char szArray[20] = { "123456789"};
	printf("����&-- 	char szArray[20] = { \"123456789\"}; ,szArray��ַ = %x\n" ,szArray+0);
	char * ptrQuot = NULL;
	ptrQuot = szArray;
	*ptrQuot = '2';
	cout << "*ptrQuot = "<< *ptrQuot <<" szArray = " << szArray << endl;
	printf("����&-- 	ptrQuot = &szQuot; *ptrQuot = %C ,szArray[] = %s ,  ptrQuot��ַ = %x\n\n" ,*ptrQuot, szArray , ptrQuot);


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
ptrC��ַ = 22fde0, szBuffer ��ַ = 22fde0

char &szQuot = char szObject = 'O';      szQuot = O     char* ptrB = & szQuot;
*ptrB = O
cahr* ptrB = & szQuot;  ptrB ��ַ = 22fddf , szQuot ��ַ = 22fddf �� szObject ��
ַ = 22fddf

szQuot = 'W'; szObject = W ;      szQuot = W     *ptrB = W
cahr* ptrB = & szQuot;  ptrB ��ַ = 22fddf , szQuot ��ַ = 22fddf �� szObject ��
ַ = 22fddf

*ptrB  = 'K';; szObject = K ;     szQuot = K     *ptrB = K
cahr* ptrB = & szQuot;  ptrB ��ַ = 22fddf , szQuot ��ַ = 22fddf �� szObject ��
ַ = 22fddf

����&--         char szArray[20] = { "123456789"}; ,szArray��ַ = 22fdc0
*ptrQuot = 2 szArray = 223456789
����&--         ptrQuot = &szQuot; *ptrQuot = 2 ,szArray[] = 223456789 ,  ptrQuo
t��ַ = 22fdc0


44      43      42      41

22fdbc  22fdbd  22fdbe  22fdbf

--------------------------------
Process exited after 0.5274 seconds with return value 0
�밴���������. . .

*/
