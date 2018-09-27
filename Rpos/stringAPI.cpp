/******************************************************************
* Author: Sam
* Function:
* Time:2018-05-21 17:01:21 
* Description: 测试string的各种库函数
* *******************************************************************/

#pragma warning(disable:4996)

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include<sstream>
#include <windows.h>

#define CODEBLOCK 12

using namespace std;

void display(string strTemp, string mystr)
{
	cout << "strTemp : " << strTemp << endl;
	cout << "mystr : " << mystr << endl;
}

int main()
{


	int i = 110;
	int iPos = 0;
	char c;
	char ch[] = { "hello string class" };
	char szTemp[10] = { "\0" };
	string::iterator it;
	string::reverse_iterator r_it;//反向迭代器用反向迭代器指针 reserve_iterators
	cout << "init." << endl;
	string strTemp(ch);
	string mystr(strTemp, 0, 13);
	stringstream ss_all; //#include<sstream>

	int iExternRecNum = 1;
	long lTemp = 0;
	string reff = "0";


	switch (CODEBLOCK)
	{
	case 1:
		//swap
		display(strTemp, mystr);
		cout << "swap" << endl;
		swap(strTemp, mystr);
		display(strTemp, mystr);
		break;
	case 2:
		//长度，容量，为空
		cout << "strTemp.size() " << strTemp.size() << endl;
		cout << "mystr.length() " << mystr.length() << endl;
		cout << "mystr.empty" << mystr.empty() << endl;
		cout << "mystr.capacity() " << mystr.capacity() << endl;
		break;
	case 3:
		//compare
		cout << "mystr.compare(str) :" << mystr.compare(strTemp) << endl;
		cout << "mystr.compare(1,3,str) : " << mystr.compare(1, 3, strTemp) << endl;
		cout << "mystr.compare(1,3,str,str.begin()+1,str.begin()+3) : " << mystr.compare(1, 3, strTemp, 1, 3);
		break;
	case 4:
		//find  \ redirection_find
		cout << endl << "find   redirection_find" << endl;
		cout << "mystr.find() : " << mystr.find('s') << endl;
		cout << " mystr.find_first_of(c, pos) :" << mystr.find_first_of('s', 0) << endl;
		break;
	case 5:
		///find_last_of()
		//find_firrst_not_of
		//返回在当前字符串中第一个不匹配ch字符的索引, 从index开始搜索, 没用收获则返回string::npos
		cout << "mystr.find_first_not_of('r',0) ： " << mystr.find_first_not_of('s', 0) << endl;
		break;
	case 6:
		//流处理
		cout << endl << "*************" << endl << "string stream :." << endl;
		
		ss_all << i;
		ss_all >> c;
		cout << "int " << i << " to char :" << c << endl;
		ss_all << c;
		ss_all >> i;
		cout << "char " << c << "to int " << i << endl;
		break;
	case 7:
		//定位
		cout << "mystr.at[3] " << mystr.at(3) << endl;
		mystr.replace(1, 3, "sam");
		mystr.push_back('#');
		cout << "\n***mystr.push_back('#'): " << mystr << endl;
		mystr.append(strTemp);
		cout << "\n***mystr.append(str) : " << mystr << endl;
		break;
	case 8:
		//查找函数，迭代器
		/*
		w)begin() end() //提供类似STL的迭代器支持
		x) rbegin() rend() //逆向迭代器
		y) get_allocator() //返回配置器
		*/
		strTemp = "hello";
		cout << "string " << strTemp << endl;
		//it = strTemp.begin();
		r_it = strTemp.rbegin();

		cout << "it = string.begin() : *r_it = " << *r_it << endl;
		it = strTemp.end() - 1;
		cout << "it = string.end():it= " << *it << endl;
		break;
	case 9:
		//限制string长度到实际大小
		strTemp = "hello,world   ";
		cout << strTemp <<"#"<< endl;
		cout <<"strTemp.capacity() : " << strTemp.capacity()<<endl;		//返回当前容量（即string中不必增加内存即可存放的元素个数）
		cout << "strTemp.size();" << strTemp.size() << endl;			 //返回string对象中可存放的最大字符串的长度
		cout << "strTemp.length(): " << strTemp.length() << endl;
		cout << "strTemp.max_size() : " << strTemp.max_size() << endl;
		strTemp.resize(strTemp.length());
		cout << "strTemp.resize(): " << strTemp<<endl;

		strTemp = "hello,world   ";
		cout << strTemp << "#" << "size: " << strTemp.size() << endl;
		strTemp.reserve();
		cout << strTemp << "#" << "size: " << strTemp.size() << endl;
		break;
	case 10:
		//erase;
		strTemp = "hello,world    1";
		cout << "strTemp : " << strTemp << endl;
		iPos = strTemp.find_first_of(" ");
	//swi	strTemp.erase(iPos, strTemp.length());
		strTemp.erase(iPos,99);
		cout << "strTemp.erase() : " << strTemp << "end"<<endl;
		break;
	case 11:
		//char to shr;
		iPos = 123456789;
		_itoa_s(iPos, szTemp, 10);
		//strTemp = itoa(iPos, szTemp, 10);
		cout << "iPos :"<<iPos
			<<"\t itoa(iPos, ch, 10) = " << szTemp << endl;
		break;
	case 12:
		lTemp = 0;
		iExternRecNum = 1;
		
		lTemp = 100000000 + iExternRecNum;
		itoa(lTemp, szTemp, 10);
		reff.clear();
		reff = "J";
		reff += szTemp;				//内部会员订单号//订单编号；利用静态变量保持rec_num从1递增；
		cout << "reff : "<< reff << endl;

		//
		iExternRecNum = 123456789;
		reff = "J000000000";
		itoa(iExternRecNum, szTemp, 10);
		reff.replace(10 - strlen(szTemp), strlen(szTemp), szTemp);
		cout << "reff : " << reff << endl;
		break;
	default:
		mystr.erase();
		strTemp.clear();
		mystr.~string();
	}

	//CTR+SHIFT+h VS查找替换
	//测试多行查找的命令

	//sam 
 //00ith
	
	//sam
	//smith
	system("pause");
	return 0;

}
