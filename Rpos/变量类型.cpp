// �жϱ�������

#include <iostream>> 
#include <typeinfo>


using namespace std;

int main() 
{
	int iVariable =10; 
	string strVariable ="hello,world";
	if(typeid(iVariable) == typeid(int)) 
	{
		cout<<"int ����"<<endl;
	}
	else
	{
		cout<<"int �ж�ʧ��\n";
	 } 
	if(typeid(strVariable) == typeid(string))
	{
		cout<<"string ����"<<endl;
	}
	else
	{
		cout<<"string �ж�ʧ��\n" ;
	} 
	return 0;
}

