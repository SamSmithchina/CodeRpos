//#define _CRT_SECURE_NO_WARNINGS   //�رհ�ȫ���
#include <iostream>
#include <malloc.h>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
    int nResult = -2;//���S1��S2��ͬ����0������ͬ����-1,���Գ�ʼֵ����Ϊ-2
    int nCount = 12;
    char *S1 = "Frankie is best!\0";
    char *S2 = "Frankie is no good!\0";
    nResult = memcmp(S1, S2, nCount);
    if (nResult == 0)
    {
        std::cout << "S1��S2�ڵ�" << nCount << "λ��ǰ��ͬ" << endl;
    }
    else
    {
        std::cout << "S1��S2�ڵ�" << nCount << "λ��ǰ����ͬ" << endl;
    }
    system("pause");
    return 0;
}
