/* 2018-09-07 17:24:53
 ��������ڴ� �� memset���� ����չ�ڴ档  �ڴ�memset���㣻 �ͷ��ڴ�

*/
/*
void * memset ( void * ptr, int value, size_t num );
��1�� ��ptrָ��char�͵�ַ��value��Ϊ�����ַ�ֵ��
��2�� ��ptrָ���char�ͣ���int�͵�ַ��Ҫ�븳ֵ��ȷ��value��ֵֻ����-1��0��
��Ϊ-1��0ת���ɶ����ƺ�ÿһλ����һ���ģ���int��ռ4���ֽڣ���-1=0XFFFFFFFF, 0=0X00000000��
*/
#include<iostream>
#include <memory>
#include <cstring>

using namespace std;

int main()
{
    long long* llParam = NULL;
    llParam = new long long[10] ;
    memset(llParam ,0, sizeof(llParam) ) ;    //memset��������������ǽ������Ե����ֽ���������ķ�ʽ�ŵ�ָ�����ڴ���ȥ
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
