//#define _CRT_SECURE_NO_WARNINGS
//#include "ReadFile.cpp"
//#include "WriteFile.cpp"
//
#include "head.h"

int main()
{

	char *FileName = NULL;


	FileName = (char*)malloc(21 * sizeof(char));
	FileName = GetName(FileName);//定义文件名


	if (WriteFile(FileName))//写文件
	{
		printf("writing operation is ok!\n");
	}
	else
	{
		printf("writing operation is failure!\n");
	}

	if (ReadFile(FileName))//读文件
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

	printf("按任意键结束 %c", getchar());
	getchar();
	return 0;
}