		#include <iostream>
using namespace std;

void ExitTest(int i )
{
	if(7 < i)					//����ִ�е�i=8 ���ͻ���ֹ��֮���ѭ��������ִ�У� 
	{
		exit(0); 	
	}
	else
	{
		cout << "i = " << i <<endl;
	}
}

int main()
{
	int i =0;
	for( i =0; i<10; i++)
	{
		ExitTest (i);
	}
	return 0;
}
