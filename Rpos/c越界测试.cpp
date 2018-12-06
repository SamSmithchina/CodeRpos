#include <iostream> 
#include <iomanip>
using namespace std;

int main()
{
	char szTemp[257] ={"\0"};
	int i =0;
	for(i =0; i <10 ;i++)
	{
		cout << setw(4)  << i;//<< setiosflag(ios::left)
	}
	for(i =0 ; i < 257; i++)
	{
		szTemp[i] = i;
		cout << setw(4) << szTemp[i %128];
		if(0 == (i%10))
		{
			cout << endl;
		}
	}
	//故意越界 ，看编译器是否报错； 
	cout << endl <<  "故意越界 ： " << szTemp[258] << endl; 
	
	return 0;
}
