//例13.5 通过测试cin的真值，判断流对象是否处于正常状态。

#include <iostream>
using namespace std;
int main( )
{
	float grade;
	cout<<"enter grade:";
	while(cin>>grade)//能从cin流读取数据
	{
		if(grade>=85) cout<<grade<<"GOOD!"<<endl;
		if(grade<60) cout<<grade<<"fail!"<<endl;
			cout<<" enter grade:";
	}
 	cout<<"The end. "<<endl;
 	return 0;
}
