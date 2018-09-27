/****************************************************************** 
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		 
* Description:  组合 方法 ， 对五种颜色的球选择不同三个颜色做一组，给出所有可能的颜色组合

* ***********************************************************************/
#ifndef __COMBINE_H__
#define __COMBINE_H__

#include <iostream>
#include <iomanip>
using namespace std;

enum color{ red, green, pink, glod, yellow };

//输入五种枚举颜色；
//输出其中3种不同颜色的组合， 可以重复
//思想： 设置三层循环，每层循环选择从red -> yellow 中的一种颜色，
void Combine()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int n = 0;
	color clr[3];

	for (i = 0; i < 5; i++)	//组合选出的第一颜色
	{
		clr[0] = (enum color)i;
		for (j = 0; j < 5; j++)//组合选出的第二颜色
		{
			clr[1] = (enum color)j;
			if (clr[1] == clr[0])
			{
				continue;
			}
			for (k = 0; k < 5; k++)//组合选出的第三颜色
			{
				clr[2] = (enum color)k;
				if (clr[2] != clr[0] && clr[2] != clr[1])
				{
					cout << setw(8) << clr[0] << setw(8) << clr[1] << setw(8) << clr[2] << endl;
					for (n = 0; n < 3; n++)
					{
						switch (clr[n])
						{
						case 0:
							cout <<setw(8)<< "red";
							break;
						case 1:
							cout << setw(8) << "green";
							break;
						case 2:
							cout << setw(8) << "pink";
							break;
						case 3:
							cout << setw(8) << "gold";
							break;
						case 4: 
							cout << setw(8) << "yellow";
							break;
						default:
							cout << setw(8) << endl;

						}//switch
					}
					
				}//if
			}// 3
		}//2
	}// 1


}

#endif