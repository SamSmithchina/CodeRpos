/*
//	Author: sam smith
//	Date:  2018-06-10 19:11:14
//	Description: 测试 string + string + string 的操作如何正确。

*/

#include<iostream>
//#include <stdlib.h>
#include <string>

using namespace std;

int main()
{

	string strA = "hello";
	string strB = " world";
	string strC = "\t";
	string strD = "";
	string strE = "";

	//ordwth 接口字段格式初始化，理应 const,为在后续使用中修改，没有设置静态;
 const std::string date ( "20180605");		//日期年月日
 const std::string strtime ( "12:13:14");	//时间时分秒
 const std::string reff ( "J100000000");		//内部会员订单号
 const std::string account ("A645078963");	//股票账号
 const std::string stock ( "100000");		// 证券代码
 const std::string bs ( "B");				//买卖
 const std::string price ( "10.000");		//价格
 const std::string qty ( "200");				// 成交原始数量，多个验股测试样例时，检查股份需要递增
 const std::string status ( "R");			//R表示未发送，P表示已发送
 const std::string owflag ( "LPT");			//订单类型标志 撤单WTH
 const std::string orderc ( "0");			//撤单号 = rec_num
 const std::string frimid ( "");				//B股的发行结算代码，对A股无意义；
 const std::string brandchid ("");			//营业部代码
 const std::string checkord ( "0x00000000000000000000000000000000");//binary 校验码
// const std::string checkord ( "0x0");		//binary 校验码
 const std::string rec_num ( "1");			//订单编号；
	//插入订单信息
	 std::string OrdwthStruct = "('" + date + "'," + "'" + strtime + "'," + "'" + reff + "'," + "'" + account + "'," + "'"
+ stock + "'," + "'" + bs + "'," + "'" + price + "'," + "'" + qty + "'," + "'" + status + "'," + "'"
+ owflag + "'," + "'" + orderc + "'," + "'" + frimid + "'," + "'" + brandchid + "'," + "'" + checkord + "'," + "'" + rec_num + "')";

    std::string newOrdwthStruct = "('" + "20180605" + "'," + "'" + "12:13:14" + "'," + "'" + "J100000000" + "'," + "'" + "A645078963" + "'," + "'"
+ "100000" + "'," + "'" + "B" + "'," + "'" + "10.000" + "'," + "'" + "200" + "'," + "'" + "R" + "'," + "'"
+ "LPT" + "'," + "'" + "0" + "'," + "'" + "" + "'," + "'" + "" + "'," + "'" + "0x00000000000000000000000000000000"
+ "'," + "'" + "1" + "')";
	cout<<"strD :"<<strD<<endl;
	cout<<"strE :"<<strE<<endl;

	//strD = strA + strB + strC ;
	strE = strD + strD + strD + strD;
	cout<<"strD :"<<strD<<endl;
	cout<<"strE :"<<strE<<endl;

	cout<<"newOrdwthStruct : "<<newOrdwthStruct<<endl;
	cout<< "OrdwthStruct : "<<OrdwthStruct<<endl;
	return 0;
 }
