#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	//�Ǻ� ָ��
	char *ptrC =NULL;
	char szBuffer[20] =  {"hello,world"};
	ptrC = szBuffer ;
	cout <<  "szTemp = *ptrC  ,szTemp = " << *ptrC <<std::endl;

	//����ָ������
	char szObject = 'O';
	char &szQuot = szObject;
	cout <<  "char &szQuot = szObject;  szQuot = " << szQuot <<std::endl;
	ptrC = & szQuot;
	cout <<  "ptrC = & szQuot;  *ptrC = " << *ptrC <<std::endl;

	//ȡ��ַ
	printf( "����&-- 	ptrC = & szQuot;         ��ַptrC    = %x\n" , ptrC);
	//������
	ptrC = NULL;
	ptrC =  &szObject;
	printf("����&-- 	char szObject = 'O';     szObject��ַ = %x\n " , ptrC);
	ptrC = NULL;
	ptrC = &szQuot;
	printf("����&-- 	char &szQuot = szObject;  ,szQuot��ַ = %x\n" ,ptrC);

	char szArray[20] = { "123456789"};
	printf("����&-- 	char szArray[20] = { \"123456789\"}; ,szArray��ַ = %x\n" ,szArray+0);
	char * ptrQuot = NULL;
	ptrQuot = &szQuot+0;
	*ptrQuot = '2';
	cout << "*ptrQuot = "<< *ptrQuot <<" szArray = " << szArray << endl;
	printf("����&-- 	ptrQuot = &szQuot; ,ptrQuot��ַ = %x\n" ,ptrQuot);


	int i = 0x41424344;
	int *pi;
	char *pc;
	pi = &i;
	pc = (char *)pi;
	printf("\n%x\t%x\t%x\t%x\n", pc[0], pc[1], pc[2], pc[3]);
	printf("\n%x\t%x\t%x\t%x\n", pc+0, pc+1, pc+2, pc+3);

	return 0;
}
