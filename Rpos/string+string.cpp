/*
//	Author: sam smith
//	Date:  2018-06-10 19:11:14
//	Description: ���� string + string + string �Ĳ��������ȷ��

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

	//ordwth �ӿ��ֶθ�ʽ��ʼ������Ӧ const,Ϊ�ں���ʹ�����޸ģ�û�����þ�̬;
 const std::string date ( "20180605");		//����������
 const std::string strtime ( "12:13:14");	//ʱ��ʱ����
 const std::string reff ( "J100000000");		//�ڲ���Ա������
 const std::string account ("A645078963");	//��Ʊ�˺�
 const std::string stock ( "100000");		// ֤ȯ����
 const std::string bs ( "B");				//����
 const std::string price ( "10.000");		//�۸�
 const std::string qty ( "200");				// �ɽ�ԭʼ�����������ɲ�������ʱ�����ɷ���Ҫ����
 const std::string status ( "R");			//R��ʾδ���ͣ�P��ʾ�ѷ���
 const std::string owflag ( "LPT");			//�������ͱ�־ ����WTH
 const std::string orderc ( "0");			//������ = rec_num
 const std::string frimid ( "");				//B�ɵķ��н�����룬��A�������壻
 const std::string brandchid ("");			//Ӫҵ������
 const std::string checkord ( "0x00000000000000000000000000000000");//binary У����
// const std::string checkord ( "0x0");		//binary У����
 const std::string rec_num ( "1");			//������ţ�
	//���붩����Ϣ
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
