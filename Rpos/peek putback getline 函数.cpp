//例13.9 peek函数和putback函数的用法。
#include <iostream>
using namespace std;
int main( )
{char c[20];
 int ch;
 cout<<"please enter a sentence:"<<endl;
 cin.getline(c,15,' ');
 cout<<"The first part is:"<<c<<endl;
 
 ch=cin.peek( );//观看当前字符
 cout<<"The next character(ASCII code) is:"<<ch<<endl;
 
 //putback函数调用形式为cin.putback(ch)，
 //其作用是将前面用get或者getline函数从输入流中读取的字符ch返回到输入流，插入到当前指针的位置，供后面读取。
 cin.putback(c[0]);             //将′I′插入到指针所指处 
// cin.ignore();
 cin.getline(c,15,'\n');
 cout<<"The second part is:"<<c<<endl;
 return 0;
}
