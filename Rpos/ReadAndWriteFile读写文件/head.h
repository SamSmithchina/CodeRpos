#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#ifndef HEAD_H
#define HEAD_H

//该头文件为工程文件的读/写目标文件定义和读与写操作函

//功能为获取待读取文档名称
//该函数为读/写公用函数

char* GetName(char* FileName)
{
	//char name[81] = { "" };
	
	printf("please enter the file's name which you want to read\n");

	scanf("%s", FileName);//安全警告
	//gets(FileName);
	//文件以.txt格式，
	strcat(FileName ,".txt" );
	printf("file name is %s\n",FileName);
	return FileName;
}

//读取操作
bool ReadFile(char *FileName)
{
	FILE *file = NULL;
	char c = '1';
	
	//读取文件并且输出
	file = fopen(FileName, "r");
	if (file == NULL)
	{
		printf("cann't read %s,please check file's name\n",FileName);
		return false;
	}
	printf("\n reading operation is begining\n");
	while (!feof(file))
	{
		//c = getc(file);
		fscanf(file,"%c",&c);
		printf("%c",c);
	//	c = getchar();
	}
	
	//printf("reading operation is end\n");
	fclose(file);
	return (true);
}

bool WriteFile(char *FileName)
{
	FILE *file = NULL;
	char c = '#';//'#'为输入结束符
	file = fopen(FileName, "w");
	if (file == NULL)
	{
		printf("cann't open %s ,please check it!\n", FileName);
		return false;
	}
	getchar();//吸收输入缓冲的回车
	printf("please enter your information,and input '#' to finish!\n");

	scanf("%c", &c);
	while (c != '#')
	{
		fprintf(file,"%c",c);
		
		printf("%c", c);
		scanf("%c", &c);
	}
	fclose(file);
	printf("\n");
	return true;
}
#endif HEAD_H