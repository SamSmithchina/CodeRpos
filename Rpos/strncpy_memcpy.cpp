#define _CRT_SECURE_NO_WARNINGS//�رհ�ȫ���
#include <iostream>
#include <malloc.h>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
    char * src = "Hello Frankie World !\0";
    char * dest = newchar[50];
    char * dest1 = newchar[50];
    char * dest2 = newchar[50];
    memset(dest, 0, 50);
    memset(dest1, 0, 50);
    memset(dest2, 0, 50);
    memcpy(dest, src, 7);
    strcpy(dest1, src);
    strncpy(dest2, src, 7);
    std::cout << "dsetֵΪ��" << dest << endl;
    std::cout << "dset1ֵΪ��" << dest1 << endl;
    std::cout << "dset2ֵΪ��" << dest2 << endl;
    system("pause");
    return 0;
}
