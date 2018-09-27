/****************************************************************** 
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		 2018年7月10日10:17:25
* Description:  测试 左加加 右加加 的速度；观察具体汇编代码

* ***********************************************************************/
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <mutex>

//测试左++ 和 右++ 的速度； 一定注意检查关键的左右++汇编代码
//edit: sam				time: 2018-07-10 09:43:32
//	Speed.PlusPlus
int main( )
{
	int i = 0;
	int iTemp = 0;
	time_t end;
	time_t end2;
	time_t begin;
	time_t begin2;
	int iTimes = 100000000; 
	std::mutex m1;

	for (int j = 0; j < 10; j++)
	{
		m1.lock();
		begin = clock();
		{
			for (i = 0; i < iTimes;)	//一万次 左++
			{
				iTemp = ++i;
				//	std::cout<<iTemp<<std::endl;
			}
		}
		end = clock();
		m1.unlock();

		iTemp = 0;
		m1.lock();
		begin2 = clock();
		{
			for (i = 0; i < iTimes;)
			{
				iTemp = i++;
				//	std::cout<<iTemp<<std::endl;
			}
		}
		end2 = clock();
		m1.unlock();

		std::cout << "++i : = " << " 用时 ： " << end - begin ;
		std::cout << "\t i++ : = " << " 用时 ： " << end2 - begin2 << std::endl;
	}
	getchar();
	return 0;
}


/*
输出：
100000000次：
++i : =  用时 ： 266     i++ : =  用时 ： 188
++i : =  用时 ： 265     i++ : =  用时 ： 188
++i : =  用时 ： 266     i++ : =  用时 ： 187
++i : =  用时 ： 266     i++ : =  用时 ： 187
++i : =  用时 ： 266     i++ : =  用时 ： 188
++i : =  用时 ： 265     i++ : =  用时 ： 188
++i : =  用时 ： 265     i++ : =  用时 ： 188
++i : =  用时 ： 266     i++ : =  用时 ： 187
++i : =  用时 ： 266     i++ : =  用时 ： 187
++i : =  用时 ： 250     i++ : =  用时 ： 203


ASM : ++i
mov         eax,dword ptr [i]
add         eax,1
mov         dword ptr [i],eax

ASM : i++
mov         eax,dword ptr [i]
add         eax,1
mov         dword ptr [i],eax


ASM : iTemp = ++i;
00928D73  mov         eax,dword ptr [i]  
00928D76  add         eax,1  
00928D79  mov         dword ptr [i],eax  
00928D7C  mov         ecx,dword ptr [i]  
00928D7F  mov         dword ptr [iTemp],ecx  

ASM : iTemp = i++;
00928DD6  mov         eax,dword ptr [i]  
00928DD9  mov         dword ptr [iTemp],eax  
00928DDC  mov         ecx,dword ptr [i]  
00928DDF  add         ecx,1  
00928DE2  mov         dword ptr [i],ecx  

*/