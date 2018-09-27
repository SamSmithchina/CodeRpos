//#define _CRT_SECURE_NO_WARNINGS   //关闭安全检查
#include <iostream>
#include <malloc.h>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
    int nResult = -2;//如果S1，S2相同返回0，不相同返回-1,所以初始值设置为-2
    int nCount = 12;
    char *S1 = "Frankie is best!\0";
    char *S2 = "Frankie is no good!\0";
    nResult = memcmp(S1, S2, nCount);
    if (nResult == 0)
    {
        std::cout << "S1与S2在第" << nCount << "位置前相同" << endl;
    }
    else
    {
        std::cout << "S1与S2在第" << nCount << "位置前不相同" << endl;
    }
    system("pause");
    return 0;
}
