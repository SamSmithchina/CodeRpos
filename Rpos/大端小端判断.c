#include <stdio.h>
#include <stdlib.h>

int main(void) {
	union {
		short s;
		char c[sizeof (short)];
	} un;
	un.s = 0x0102;
	if (un.c[0] == 1 && un.c[1] == 2)
		printf("big-endian\n");
	else if (un.c[0] == 2 && un.c[1] == 1)
		printf("little-endian\n");
	else
		printf("unknown\n");

	exit(0);
}
//little-endian
//
//--------------------------------
//Process exited after 0.2536 seconds with return value 0
//�밴���������. . .

//---------------------
//���ߣ�gochenguowei
//��Դ��CSDN
//ԭ�ģ�https://blog.csdn.net/gochenguowei/article/details/79997561
//��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�
