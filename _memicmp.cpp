#define _CRT_SECURE_NO_WARNINGS//�رհ�ȫ���
#include <iostream>
#include <malloc.h>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
    int nResult = -2;
    int nCount = 3;
    char * S1 = "ABC\0";
    char * S2 = "abc\0";
    nResult = _memicmp(S1, S2, nCount);
    if (nResult == 0)
    {
        std::cout << "S1 �� S2 ��ͬ �������ִ�Сд" << endl;
    }
    system("pause");
    return 0;
}

/*
�ر�ע���������memcmp���ԣ�memicmp��������ĸ��Сд

�������أ����S1��S2��ͬ����0������ͬ����-1
*/
