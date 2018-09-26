#include <stdio.h>

int main(void)
{
    double a =16;
    printf("a1=%lf\na4=%d\na2=%o\na3=%x\n",a,a,a,a);
    
    printf("%lf \n ", (double)a );
    printf("%d \n", (int)a); 
    printf("%d \n", a); 
    printf("%0 \n", (int)a);
    printf("%x \n", (int)a);
	
	return 0;
}

/*
在C语言中，要输出%不能直接使用%，因为%在C语言输入输出中，是用作格式通配符存在的，如%d,%f等。
所以，要输出百分号，需要使用转义字符。
该转义字符的规定为
%%
*/
//%x 16进制和%o 8进制都是用来输入/输出整型的格式化字符，可以用在C语言的格式化输入输出函数中。

//数据截断，顾名思义，根据要求，将数据的高字节数据截去，只保留低字节部分。很容易理解。 
