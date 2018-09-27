/****************************************************************** 
*  
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		
* Version：V .	.	
  
* Description: 

* Editor：           
* Time：               
* Modification： 


* ************************************************************************
* Copyright (c) $NULL$ ￥ShenZhen Kindom Cor., Ltd.￥ All rights reserved.
* ***********************************************************************/

#include <iostream>

#include <Windows.h>

#include"headh.h"

//#include "head.cpp" 
//如果这里包含head.cpp ，会报错重定义；

extern void Byebye();

int main()
{
	Print();

	Byebye();

	system("pause");
	return 0;
}

//这个实验可以得出以下结论：
//c++在.h 文件中声明定义；
//在.cpp 文件中赋值和实现；
//head.cpp中实现函数体不需引用 head.h ；
//main.cpp调用函数包含head.h  就可以；
//另外不单独在.cpp中写一个函数再在主函数中调用它；正确方式是在.h中写函数
//