// 判断变量类型

#include <iostream>> 
#include <typeinfo>


using namespace std;

int main() 
{
	int iVariable =10; 
	string strVariable ="hello,world";
	if(typeid(iVariable) == typeid(int)) 
	{
		cout<<"int 类型"<<endl;
	}
	else
	{
		cout<<"int 判断失败\n";
	 } 
	if(typeid(strVariable) == typeid(string))
	{
		cout<<"string 类型"<<endl;
	}
	else
	{
		cout<<"string 判断失败\n" ;
	} 
	return 0;
}

