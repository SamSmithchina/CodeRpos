/****************************************************************** 
*  
* Author：Sam Smith   wangbingzong@szkindom.com
* Time： 2018-05-24 14:00:37
* Version：V ... 
* Description：TCP Client
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


#include<WinSock2.h>
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
#include<WS2tcpip.h>
#include<sys/types.h>
#include<sys/utime.h>
//#include<unistd.h>
#pragma comment(lib,"ws2_32.lib")

using namespace std;
//简单的发送和接受消息客户端
int main()
{
	//socket()
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	struct fd_set rfds;
	int rd_count=0,select_val=0;
	timeval time_val;

	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}

	//create socket word
	while (1)
	{
		SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (client == INVALID_SOCKET)
		{
			cout << "invalid socket" << endl;
		}
		//server address
		sockaddr_in serveraddr;
		serveraddr.sin_family = AF_INET;
		serveraddr.sin_port = htons(8888);
		inet_pton(AF_INET, "127.0.0.1", (void*)&serveraddr.sin_addr.S_un.S_addr);
		//FD_SET 
		//coonnect()
		if (connect(client, (sockaddr*)&serveraddr, sizeof(serveraddr))
			== SOCKET_ERROR)
		{
			cout << "connect() is  error " << endl;
			continue;
		}
		FD_ZERO(&rfds);	//  /*把可读文件描述符的集合清空*/
		//FD_SET(0, &rfds);	///*把标准输入的文件描述符加入到集合中*/
		rd_count = 0;

		FD_SET(client, &rfds);	// /*把当前连接的文件描述符加入到集合中*/
		if (rd_count < client)	///*找出文件描述符集合中最大的文件描述符*/  
			rd_count = client;
		///*设置超时时间*/
		time_val.tv_sec = 3;
		time_val.tv_usec = 0;
		
		//select()
		select_val = select(rd_count + 1, &rfds, NULL,NULL, 0);	//linux select
		


		if (select_val == -1)
		{
			cout << "select() fail!" << endl;
			continue;
		}
		else if (select_val == 0)
		{
			cout << "no input infor, no output !" << endl;
			continue;
		}
		else
		{
			if (FD_ISSET(client, &rfds))
			{
				//recv()
				//connect the server ok , recv() 
				char receiverdata[255];
				cout <<endl<< "form server : ";
				int ret = recv(client, receiverdata, 255, 0);
				if (ret > 0)
				{
					receiverdata[ret] = 0x00;
					cout << receiverdata << endl << endl;
				}
			}
			if (FD_ISSET(0, &rfds))
			{
				//connect the server ok, send() 
				cout << endl<<"client :";
				string data;
				cin >> data;
				const char *senddata;
				senddata = data.c_str();	//string type change to char* type
				send(client, senddata, strlen(senddata), 0);
			}
		}
		
	

		//closesocket(client);
		closesocket(client);
	}

	WSACleanup();
	return 0;
}

