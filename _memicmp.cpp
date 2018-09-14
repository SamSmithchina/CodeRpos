#define _CRT_SECURE_NO_WARNINGS//关闭安全检查
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
        std::cout << "S1 与 S2 相同 ，不区分大小写" << endl;
    }
    system("pause");
    return 0;
}

/*
特别注明：相对于memcmp而言，memicmp不区分字母大小写

函数返回：如果S1，S2相同返回0，不相同返回-1
*/
