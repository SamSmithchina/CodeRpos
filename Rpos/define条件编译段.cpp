#include <iostream> 
using namespace std; 

//#define RUN                                 //�ڵ��Գ���ʱʹ֮��Ϊע���� 
int main( ) 
{
 	int x=1,y=2,z=3; 
	#ifdef RUN                               
	 //����Ϊ������������
	 cout<<"x= "<<x<<" y= "<<y<<" z= "<<z<< endl; //�ڵ��Գ���ʱ��Ҫ�����Щ��Ϣ ,#endif��Ϊ������������ 
 	
	#endif                                

	cout<< "x*y*z=" << x*y*z <<endl; 
	return 0; 
}
