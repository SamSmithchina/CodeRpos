/* ***************************************************************** 
*  
* Author��Sam Smith   wangbingzong@szkindom.com
* Time�� 
* Version��V ... 
* Description��
*
* Editor��           
* Time��               
* Modification�� 
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

//��7.8 �ڴ����к졢�ơ������ס���5����ɫ�������ɸ���ÿ�δӿڴ�������ȡ��3����
//�ʵõ�3�ֲ�ͬ��ɫ����Ŀ���ȡ�������ÿ�����е������

#include <iostream>
#include <iomanip>                             //�����ʱҪ�õ�setw���Ʒ�
using namespace std;
int main()
{
	enum color { red, yellow, blue, white, black };      //����ö������color
	color pri;                                     //����color���͵ı���pri
	int i, j, k, n = 0, loop;                            //n���ۼƲ�ͬ��ɫ�������
	for (i = red; i <= black; i++)  
	{                     //��iΪĳһ��ɫʱ 
		for (j = red; j <= black; j++)                     //��jΪĳһ��ɫʱ
		{
			if (i != j)                                 //��ǰ���������ɫ��ͬ
			{
				for (k = red; k <= black; k++) //ֻ��ǰ���������ɫ��ͬ������Ҫ����3�������ɫ
				{
					if ((k != i) && (k != j))   //3�������ɫ����ͬ
					{
						n = n + 1;                //ʹ�ۼ�ֵn��1
						
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
	cout << "total:"<< n << endl;       //���������������ϵĸ���
	return 0;
}
