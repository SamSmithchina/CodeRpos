#include <iostream>  
  
using std::cout;  
using std::cin;  
using std::cerr;  
  
int fun(int & a, int & b)  
{  
if(b == 0)  
{  
    throw "hello there have zero sorry\n"; //�����쳣  
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
      
    try //try�����ǿ��������쳣�����  
    {  
    cout << " a / b = "<< fun(a,b) << "\n";  
    }  
    catch(const char *str)  //�����쳣,�����쳣  
    {  
        cout << str;  
    cerr <<"����Ϊ0\n"; //cerr���ᵽ��������� �����ڽ��������Ҳ����ʹ��  
    }  
    }  
    system("pause");  
    return 1;  
}  
