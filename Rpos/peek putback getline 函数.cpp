//��13.9 peek������putback�������÷���
#include <iostream>
using namespace std;
int main( )
{char c[20];
 int ch;
 cout<<"please enter a sentence:"<<endl;
 cin.getline(c,15,' ');
 cout<<"The first part is:"<<c<<endl;
 
 ch=cin.peek( );//�ۿ���ǰ�ַ�
 cout<<"The next character(ASCII code) is:"<<ch<<endl;
 
 //putback����������ʽΪcin.putback(ch)��
 //�������ǽ�ǰ����get����getline�������������ж�ȡ���ַ�ch���ص������������뵽��ǰָ���λ�ã��������ȡ��
 cin.putback(c[0]);             //����I����뵽ָ����ָ�� 
// cin.ignore();
 cin.getline(c,15,'\n');
 cout<<"The second part is:"<<c<<endl;
 return 0;
}
