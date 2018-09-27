/******************************************************************
*
* Author：Sam Smith   wangbingzong@szkindom.com
* Time： 2018-05-24 14:27:48
* Version：V ...
* Description：tcp server
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


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<WinSock2.h>
#include<sys/types.h>
//#include<sys/socket.h>
#include<WS2tcpip.h>
#include<sys/utime.h>
//#include<unistd.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main()
{
	//init socket()
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	struct fd_set rfds;
	timeval time_val;
	int select_val, rd_count;
	char receiverData[255] = { "" };
	char sendDataToClient[200] = { "" };
	if (WSAStartup(sockVersion, &data) != 0)
	{
		cout << "create socket() fail! " << endl;
		return 0;
	}

	// socket()
	SOCKET serverlisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverlisten == INVALID_SOCKET)
	{
		cout << "listen socket() fail !" << endl;
		return 0;
	}

	sockaddr_in socketinput;
	socketinput.sin_family = AF_INET;
	socketinput.sin_port = htons(8888);
	socketinput.sin_addr.S_un.S_addr = INADDR_ANY;//any address  are listened
	if (bind(serverlisten, (LPSOCKADDR)&socketinput, sizeof(socketinput))
		== SOCKET_ERROR)
	{
		cout << "bin的（） is fail!" << endl;
		exit(0);
	}

	//listen()
	if (listen(serverlisten, 5) == SOCKET_ERROR)
	{
		cout << "listen() fail " << endl;
		exit(0);
	}

	SOCKET acceptSocket;
	sockaddr_in remoteAddr;
	int nAddrLen = sizeof(remoteAddr);//to get client ip address
	while (1)
	{

		//accept()
		acceptSocket = accept(serverlisten, (SOCKADDR*)&remoteAddr, &nAddrLen);
		if (acceptSocket == INVALID_SOCKET)
		{
			cout << "accept() fail " << endl;
			continue;
		}
		FD_ZERO(&rfds);			////*把可读文件描述符的集合清空*/
	//	FD_SET(0, &rfds);	// /*把标准输入的文件描述符加入到集合中*/
		rd_count = 0;

		FD_SET(acceptSocket, &rfds);	// /*把当前连接的文件描述符加入到集合中*/

		///*找出文件描述符集合中最大的文件描述符*/    
		if (rd_count < acceptSocket)
			rd_count = acceptSocket;

		//设置超时时间
		time_val.tv_sec = 3;
		time_val.tv_usec = 0;

		//聊天
		//select()
		select_val = select(rd_count, &rfds, NULL, NULL, 0);		//select
		if (select_val == -1)
		{
			cout << "select() fail!" << endl;
			continue;
		}
		else if (select_val == 0)
		{
			cout << "no input inform, no output " << endl;
			continue;
		}
		else
		{
			if (FD_ISSET(acceptSocket, &rfds))
			{
				//recv()
				//cout << "form client: ";
				strcat_s(receiverData, "");
				int ret = recv(acceptSocket, receiverData, 255, 0);
				if (ret > 0)
				{
					receiverData[ret] = 0x00;
					cout << receiverData << endl << endl;
				}
			}
			if (FD_ISSET(0, &rfds))
			{
				//send()
				strcat_s(sendDataToClient, "");
				cout << "server: ";
				cin >> sendDataToClient;
				//send(acceptSocket,"server: ",strlen("server: "),0);
				send(acceptSocket, sendDataToClient, strlen(sendDataToClient), 0);

			}
		}

		// closesocket()
		closesocket(acceptSocket);
	}

	//closesocket()
	closesocket(serverlisten);
	WSACleanup();

	return 0;
}