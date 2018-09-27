#include <iostream>  
  
using std::cout;  
using std::cin;  
using std::cerr;  
  
int fun(int & a, int & b)  
{  
if(b == 0)  
{  
    throw "hello there have zero sorry\n"; //引发异常  
}  
return a / b;  
}  
  
int main()  
{  
    int a;  
    int b;  
    while(true)  
    {  
    cin >> a;  
    cin >> b;  
      
    try //try里面是可能引发异常代码块  
    {  
    cout << " a / b = "<< fun(a,b) << "\n";  
    }  
    catch(const char *str)  //接收异常,处理异常  
    {  
        cout << str;  
    cerr <<"除数为0\n"; //cerr不会到输出缓冲中 这样在紧急情况下也可以使用  
    }  
    }  
    system("pause");  
    return 1;  
}  
