#include <iostream>

using namespace std;

void fun(int array[], int iLength)
{
	for(int i =0; i < iLength; i++)
	{
		cout<<array[i] <<" \t";
	}
	cout<<endl;
}
int main()
{
	
	int array[10] = {0};
	int iLength =10;
	
	fun(array, iLength);
	return 0;
 } 
