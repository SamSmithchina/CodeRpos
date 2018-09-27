/* 2018-09-07 17:24:53
 申请分配内存 ， memset清零 ，扩展内存。  内存memset清零； 释放内存

*/
/*
void * memset ( void * ptr, int value, size_t num );
（1） 若ptr指向char型地址，value可为任意字符值；
（2） 若ptr指向非char型，如int型地址，要想赋值正确，value的值只能是-1或0，
因为-1和0转化成二进制后每一位都是一样的，设int型占4个字节，则-1=0XFFFFFFFF, 0=0X00000000。
*/
#include<iostream>
#include <memory>
#include <cstring>

using namespace std;

int main()
{
    long long* llParam = NULL;
    llParam = new long long[10] ;
    memset(llParam ,0, sizeof(llParam) ) ;    //memset这个函数的作用是将数字以单个字节逐个拷贝的方式放到指定的内存中去
    char *ptrCH =(char*) llParam;
    int i =0;
    cout << "sizeof(long long *param) = " << sizeof(llParam)<<endl;
    for( i =0; i< 10 ;i++)
    {
        cout <<"llparam[" << i << "] =" << dec  <<llParam[i]<<endl;
    }
    for(i =0; i < (int)sizeof(llParam); i++)
    {
        cout<<"    "<< ptrCH;
        ptrCH ++;
    }

    delete [] llParam;
    return 0;
}
