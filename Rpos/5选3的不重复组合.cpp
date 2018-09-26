/* ***************************************************************** 
*  
* Author：Sam Smith   wangbingzong@szkindom.com
* Time： 
* Version：V ... 
* Description：
*
* Editor：           
* Time：               
* Modification： 
*
* ********************************************************************
* Copyright (c) $year$ ShenZhen Kindom Cor., Ltd. All rights reserved.
* *******************************************************************/

/* *****************************************************************    
* Function:         
* Description:      
* Calls:             
* Called By:         
* Input:           
* Output:            
* *******************************************************************/

//例7.8 口袋中有红、黄、蓝、白、黑5种颜色的球若干个。每次从口袋中任意取出3个球，
//问得到3种不同颜色的球的可能取法，输出每种排列的情况。

#include <iostream>
#include <iomanip>                             //在输出时要用到setw控制符
using namespace std;
int main()
{
	enum color { red, yellow, blue, white, black };      //声明枚举类型color
	color pri;                                     //定义color类型的变量pri
	int i, j, k, n = 0, loop;                            //n是累计不同颜色的组合数
	for (i = red; i <= black; i++)  
	{                     //当i为某一颜色时 
		for (j = red; j <= black; j++)                     //当j为某一颜色时
		{
			if (i != j)                                 //若前两个球的颜色不同
			{
				for (k = red; k <= black; k++) //只有前两个球的颜色不同，才需要检查第3个球的颜色
				{
					if ((k != i) && (k != j))   //3个球的颜色都不同
					{
						n = n + 1;                //使累计值n加1
						
					//	cout<<setw(8)<<i<<"   "<<j<<"   "<<k<<"   "<<endl;
					for(loop = 1; loop < 4 ;loop++)
					{
						switch(loop)
						{
							case 1: pri = color(i);break;
							case 2:	pri = color(j);break;
							case 3: pri = color(k);break;
						}
						switch(pri)
						{
							case 0: cout<<setw(8)<<"red";break;
							case 1: cout<<setw(8)<<"yellow";break;
							case 2: cout<<setw(8)<<"blue";break;
							case 3: cout<<setw(8)<<"write";break;
							case 4: cout<<setw(8)<<"black";break;
						}
						
					} 
					cout<<"   "<<n<<endl;
					}
				}
			}
		}
	}
	cout << "total:"<< n << endl;       //输出符合条件的组合的个数
	return 0;
}
