#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//替换目标串指定位置之后的字符
int main()
{
    string strSource = "J000000000";
    string strAlternate = "9876";
	string strRes;
	int i =0;
	int iMaxRound = 1000000;
    //方法一 ： str.replace()
	time_t tBegin =clock();
	{
	  for(i =0; i< iMaxRound ; i++)
    	{
    		strSource = "J000000000";
    		strRes = strSource.replace(strSource.length() - strAlternate.length() , strAlternate.length(), strAlternate);
		}
	}
	time_t tEnd = clock();
	cout << strRes << endl;
	cout << "replace() 转换 "  << iMaxRound << " 次 ， 用时 ： " << tEnd -tBegin << endl;


	//方法二
	tBegin =clock();
	{

    	for(i =0; i< iMaxRound ; i++)
   	  	{

    		strSource = "J000000000";
    		strSource.erase(strSource.length()-strAlternate.length(), strAlternate.length());
    		strRes = strSource + strAlternate;
    	}
	}
	tEnd =clock();
	cout<<strRes<<endl;
	cout << "erase() operator+ 转换 "  << iMaxRound << " 次 ， 用时 ： " << tEnd -tBegin << endl;
	
	//方法三
	tBegin =clock();
	{
		for(i =0 ; i < iMaxRound ; i++)
		{
			strSource = "J" + strAlternate;
			strRes = strSource.insert(1 ,  9-strSource.length(), '0');
		}
	}
	tEnd =clock();
	cout<<strRes<<endl;
	cout << "erase() operator+ 转换 "  << iMaxRound << " 次 ， 用时 ： " << tEnd -tBegin << endl;

	return 0;
}

/*
J000009876
replace() 转换 1000000 次 ， 用时 ： 136
J000009876
erase() operator+ 转换 1000000 次 ， 用时 ： 164
J00009876
erase() operator+ 转换 1000000 次 ， 用时 ： 329

--------------------------------
Process exited after 0.6512 seconds with return value 0
请按任意键继续. . .

*/
