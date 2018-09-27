/*
//	Author:
//	Date:
//	Description:
	
*/

#include <iostream>
#include <string> 

int main()
{
	std::string OrdwthStruct = "";
	std::string CancelOrderStruct = "";
	
//	OrdwthStruct = "('" + date + "'," + "'" + strtime + "'," + "'" + reff + "'," + "'" + account + "'," + "'"
//		+ stock + "'," + "'" + bs + "'," + "'" + price + "'," + "'" + qty + "'," + "'" + status + "'," + "'" + owflag + "'," + "'"
//		+ orderc + "'," + "'" + frimid + "'," + "'" + brandchid + "'," + "0x00000000000000000000000000000000," + "'" + rec_num + "')";
//
//	
//    CancelOrderStruct = "('" + date + "'," + "'" + strtime + "'," + "'" + reff + "'," + "'" + account + "'," + "'"
//		+ stock + "'," + "'" + bs + "'," + "'" + price + "'," + "'" + qty + "'," + "'" + status + "'," + "'"
//		+ CancelOwflag + "'," + "'" + CancelOrderc + "'," + "'" + frimid + "'," + "'" + brandchid + "',"
//		+ "0x00000000000000000000000000000000," + "'" + rec_num + "')";

 	OrdwthStruct ="'', '', '', '',  0x00000000000000000000000000000000,";
	CancelOrderStruct = "'', '', '', '',  '0x00000000000000000000000000000000'";
	std::cout<<OrdwthStruct<<std::endl;
	std::cout<<CancelOrderStruct<<std::endl;
	
	return 0;
}

