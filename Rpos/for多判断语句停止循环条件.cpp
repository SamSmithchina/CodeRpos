/*
author: sam smith ;
time �� 2018-07-31 17:51:38
function; �˽�orѭ���ж���ж���䣬����м�ĳ����䲻ͨ���� ����ѭ���Ƿ��ִ��
*/


#include <iostream>

using namespace std;

int main()
{
    int a[5] = { 0,1,2,2,4 };
    int b[5] =  { 1,2,3,4,5 };
    int i = 0;

     for( i = 0; i == a[i] && i< 5; i++)
     {

         cout<<"b[ "<<i<<" ] = "<< b[i] <<endl;
     }
    return 0;
}

/*
�����
b[ 0 ] = 1
b[ 1 ] = 2
b[ 2 ] = 3

���ۣ� ��ѭ�����м��ж�������������ѭ��������ֹ

*/
