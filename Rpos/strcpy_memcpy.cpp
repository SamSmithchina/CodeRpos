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
    memset(dest, 0, 50);
    memset(dest1, 0, 50);
    memcpy(dest, src, 7);
    strcpy(dest1, src);
    cout << "dsetֵΪ��" << dest << endl;
    cout << "dset1ֵΪ��" << dest1 << endl;
    system("pause");
    return 0;
}
