#include <stdio.h>

int main(void)
{
    double a =16;	 //double  类型 实际存储在计算机是16.000000....
	int temp = 0;
	int  iOctal = 016; //8进制 
	int iHexadecimal = 0X16; //16进制

    printf("a1=%lf\t a4=%d\t a2=%o\t a3=%x\n\n",a,a,a,a);
	
    printf("%lf \n", a );
	printf("%%d %d \n", a);		//这里的数据怎么流向寄存器的？ 下午在查看汇编
	printf("%%o %o \n", a);
	printf("%%x %x \n\n", a);

	temp = (int)a; //强制类型转换成整数
    printf("%%d %d \n", temp); 
	printf("%%o %o \n", temp);
	printf("%%x %x \n\n", temp);



	temp = 16;	//	十进制
	printf("hexadecimal hex = %x ; \t octal oct = %o \n", temp, temp); 

	
	printf("%%o %o  \n", iOctal);
	printf("%%x %x \n", iHexadecimal);
	
	system("pause");
	return 0;
}

/*
在C语言中，要输出%不能直接使用%，因为%在C语言输入输出中，是用作格式通配符存在的，如%d,%f等。
所以，要输出百分号，需要使用转义字符。该转义字符的规定为 %%
*/

//%x 16进制和%o 8进制都是用来输入/输出整型的格式化字符，可以用在C语言的格式化输入输出函数中。 八进制：以0开头，由0~7组成的数。 十六进制：以0X或0x开头，

//数据截断，顾名思义，根据要求，将数据的高字节数据截去，只保留低字节部分。很容易理解。 


//使用反汇编 点击调试->>>窗口->>反汇编 快捷键 CTRL+ALT+D