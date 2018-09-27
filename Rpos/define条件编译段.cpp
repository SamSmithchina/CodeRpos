#include <iostream> 
using namespace std; 

//#define RUN                                 //在调试程序时使之成为注释行 
int main( ) 
{
 	int x=1,y=2,z=3; 
	#ifdef RUN                               
	 //本行为条件编译命令
	 cout<<"x= "<<x<<" y= "<<y<<" z= "<<z<< endl; //在调试程序时需要输出这些信息 ,#endif行为条件编译命令 
 	
	#endif                                

	cout<< "x*y*z=" << x*y*z <<endl; 
	return 0; 
}
