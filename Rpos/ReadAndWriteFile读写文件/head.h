#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#ifndef HEAD_H
#define HEAD_H

//��ͷ�ļ�Ϊ�����ļ��Ķ�/дĿ���ļ�����Ͷ���д������

//����Ϊ��ȡ����ȡ�ĵ�����
//�ú���Ϊ��/д���ú���

char* GetName(char* FileName)
{
	//char name[81] = { "" };
	
	printf("please enter the file's name which you want to read\n");

	scanf("%s", FileName);//��ȫ����
	//gets(FileName);
	//�ļ���.txt��ʽ��
	strcat(FileName ,".txt" );
	printf("file name is %s\n",FileName);
	return FileName;
}

//��ȡ����
bool ReadFile(char *FileName)
{
	FILE *file = NULL;
	char c = '1';
	
	//��ȡ�ļ��������
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
	char c = '#';//'#'Ϊ���������
	file = fopen(FileName, "w");
	if (file == NULL)
	{
		printf("cann't open %s ,please check it!\n", FileName);
		return false;
	}
	getchar();//�������뻺��Ļس�
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