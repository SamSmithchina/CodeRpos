#include <iostream>
#include <malloc.h>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
    char* src = "Hello World\0";
    char* dst = (char*)malloc(20 * sizeof(char));//<====>char* dst = new char[7];
    memset(dst, 0, 20 * sizeof(char));
    memcpy(dst, src, 7 * sizeof(char));
    cout << "dst:" << dst << endl;
    system("pause");
    return 0;
}
