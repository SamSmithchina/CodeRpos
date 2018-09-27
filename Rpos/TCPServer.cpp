//sam smith 2018-05-24 13:25:14
//tcp  服务端
// 一对一通信

#include <stdio.h>
#include <winsock2.h>
#include<sys/types.h>
//#include<sys/socket.h>
#include<WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[])
{
    //初始化WSA windows自带的socket
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA wsaData;
    if (WSAStartup(sockVersion, &wsaData) != 0)
    {
        return 0;
    }

    //创建服务端套接字
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (slisten == INVALID_SOCKET)
    {
        printf("socket error !");
        return 0;
    }

    //服务端需要绑定ip和端口
    sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(8888);
    sin.sin_addr.S_un.S_addr = INADDR_ANY; //监听任意的地址
    if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR) //将服务端套接字与上面的ip和端口绑定
    {
        printf("bind error !");
    }

    //开始监听
    if (listen(slisten, 5) == SOCKET_ERROR)  //用listen（） 监听前面绑定好的slisten套接字
    {
        printf("listen error !");
        return 0;
    }

    //循环接受数据
    SOCKET sClient;  //创建连接的套接字
    sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr); //用于接受客户端地址
    char revData[255]; //存储接受的数据
    while (1)
    {
        printf("\nwaiting...\n");
        sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen); //和客户端 connect（）对应
        if (sClient == INVALID_SOCKET)
        {
            printf("accept error !");
            continue;
        }
        char sendBuf[20] = { '\0' };
        //printf("接受到一个接:%s \r\n", inet_ntop(AF_INET, (void*)&remoteAddr.sin_addr, sendBuf, 16));
		//cout<<
        //数据接收
        int ret = recv(sClient, revData, 255, 0);
        if (ret > 0)
        {
            revData[ret] = 0x00;
            printf(revData);
        }

        //发送数据给客户端
        const char *sendData = "Hello,TCP Client!I am TCP server\n";
        send(sClient, sendData, strlen(sendData), 0);
        closesocket(sClient);  //关闭已接通的套接字
    }


    closesocket(slisten); //关闭监听的套接字
    WSACleanup();
    return 0;
}

//Server_demo_TCP
