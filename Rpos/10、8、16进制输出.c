#include <stdio.h>

int main(void)
{
    double a =16;	 //double  ���� ʵ�ʴ洢�ڼ������16.000000....
	int temp = 0;
	int  iOctal = 016; //8���� 
	int iHexadecimal = 0X16; //16����

    printf("a1=%lf\t a4=%d\t a2=%o\t a3=%x\n\n",a,a,a,a);
	
    printf("%lf \n", a );
	printf("%%d %d \n", a);		//�����������ô����Ĵ����ģ� �����ڲ鿴���
	printf("%%o %o \n", a);
	printf("%%x %x \n\n", a);

	temp = (int)a; //ǿ������ת��������
    printf("%%d %d \n", temp); 
	printf("%%o %o \n", temp);
	printf("%%x %x \n\n", temp);



	temp = 16;	//	ʮ����
	printf("hexadecimal hex = %x ; \t octal oct = %o \n", temp, temp); 

	
	printf("%%o %o  \n", iOctal);
	printf("%%x %x \n", iHexadecimal);
	
	system("pause");
	return 0;
}

/*
��C�����У�Ҫ���%����ֱ��ʹ��%����Ϊ%��C������������У���������ʽͨ������ڵģ���%d,%f�ȡ�
���ԣ�Ҫ����ٷֺţ���Ҫʹ��ת���ַ�����ת���ַ��Ĺ涨Ϊ %%
*/

//%x 16���ƺ�%o 8���ƶ�����������/������͵ĸ�ʽ���ַ�����������C���Եĸ�ʽ��������������С� �˽��ƣ���0��ͷ����0~7��ɵ����� ʮ�����ƣ���0X��0x��ͷ��

//���ݽضϣ�����˼�壬����Ҫ�󣬽����ݵĸ��ֽ����ݽ�ȥ��ֻ�������ֽڲ��֡���������⡣ 


//ʹ�÷���� �������->>>����->>����� ��ݼ� CTRL+ALT+D