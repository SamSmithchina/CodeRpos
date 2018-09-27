/****************************************************************** 
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

/******************************************************************    
* Function:         
* Description:      
* Calls:             
* Called By:         
* Input:           
* Output:            
* *******************************************************************/

#include<iostream>
#include<limits>
#include<string>
#include<iomanip>
#include<sstream>

using namespace std;

int main()
{
	long long32_i = LONG_MAX;
	double double64 = DBL_MAX;
	double d_temp = 12345678;
	long long ll_i = 0;
	double *dptr = NULL;
	double fraction = 0;
	stringstream ss_all;
	string str = "123";
	cout << "long  size :" << sizeof(long32_i) <<"\nong32 max"<<LONG_MAX<< endl;
	cout << setprecision(16)<<"double size:" << sizeof(double64) << "\ndouble64 max:" << DBL_MAX<<endl;
	
	cout << "--------------------------------------------------" << endl;
	//cout << "d_temp ; " <<d_temp<< endl;


	//stringstream完成任意类型的转换
	//str  to double
	ss_all << str;
	ss_all >> d_temp;
	cout << "str to double :" << d_temp<<endl;

	ss_all.clear();		// clear()
	//double to str
	dptr = new double;
	*dptr = 0;
	d_temp = 1234567890.098765;
	fraction = modf(d_temp, dptr);
	ll_i = *dptr;
	cout << "d_temp is : "<<d_temp << endl;
	cout << setprecision(10) << "integer  " << *dptr << "		fraction  " << fraction << endl;

	ss_all << setprecision(63) << *dptr;//完美显示整数部分。
	ss_all >> str;

	cout << "double to str :" << str<< endl;
	system("pause");
	delete dptr;
	return 0;
}