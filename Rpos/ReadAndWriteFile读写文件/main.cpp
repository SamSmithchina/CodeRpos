//#define _CRT_SECURE_NO_WARNINGS
//#include "ReadFile.cpp"
//#include "WriteFile.cpp"
//
#include "head.h"

int main()
{

	char *FileName = NULL;


	FileName = (char*)malloc(21 * sizeof(char));
	FileName = GetName(FileName);//�����ļ���


	if (WriteFile(FileName))//д�ļ�
	{
		printf("writing operation is ok!\n");
	}
	else
	{
		printf("writing operation is failure!\n");
	}

	if (ReadFile(FileName))//���ļ�
	{
		printf("\n reading operation is ok!\n ");
		getchar();
		//return true;
	}
	else
	{
		printf("reading operation is failure!\n");
		return false;
	}

	printf("����������� %c", getchar());
	getchar();
	return 0;
}