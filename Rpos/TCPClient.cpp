//sam  smith 2018-05-24 13:24:10
// 简单 tcp 客户端,
//一对一通信
#include<WINSOCK2.H>
#include<STDIO.H>
#include<iostream>
#include<cstring>
#include <string>
#include<WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

int main()
{
    //初始化WSA windows自带的socket
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA data;
    if (WSAStartup(sockVersion, &data) != 0)
    {
        return 0;
    }

    //创建客户端套接字
    while (true)
    {
        SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //客户端套接字
        if (sclient == INVALID_SOCKET)
        {
            printf("invalid socket!");
            return 0;
        }

        sockaddr_in serAddr;
        serAddr.sin_family = AF_INET;
        serAddr.sin_port = htons(8888);
        inet_pton(AF_INET, "127.0.0.1", (void*)&serAddr.sin_addr.S_un.S_addr);
        if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) //与指定IP地址和端口的服务端连接
        {
            printf("connect error !");
            closesocket(sclient);
            return 0;
        }

        //string data;
        //cin >> data;
        //const char * sendData;
        //sendData = data.c_str(); //string转const char*
     //   char * sendData1 = "你好，TCP服务端，我是客户端\n";
        //send(sclient, sendData1, strlen(sendData1), 0);

        printf("\nInput your infor in english: \n");
        string data;
        cin >> data;
        const char * sendData2;
        sendData2 = data.c_str(); //string转const char*
        send(sclient, sendData2, strlen(sendData2), 0);


        char recData[255];
        int ret = recv(sclient, recData, 255, 0);
        if (ret>0){
            recData[ret] = 0x00;
            printf(recData);
        }
        closesocket(sclient);

    }
    WSACleanup();
    return 0;

}

//Client_demo_TCP
