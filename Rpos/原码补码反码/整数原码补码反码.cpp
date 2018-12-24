/*
ʱ�䣺 2018-12-20 17:13:19
���ܣ� ʵ����һ��int������ԭ�룬���룬����
ʵ�ַ����� ͨ��λ����õ�ԭ�룬 �ڸ�������������ԭ����÷��룬 ������Ĳ��������һ����õ�

*/


#include <iostream>
#include <string>
#include "number binary code.h"

#define STRTYPE "elemtype: "
#define STRNAME "elemname: "
#define TYPEID(x) ("typeid  : ") << (typeid(x).name())	//	(STRTYPE)
#define ELEMNAME(x) (STRNAME) << (#x)	//	(STRNAME)
#define ELEMTYPE(x) STRTYPE<<TYPEID(x)			//��Ҫʹ��C++-->Ԥ���뵽�ļ�-->ѡ���ǣ� ���ѡ�ǳ���ͻᱨ�Ҳ���ElemType.obj�ļ���

using namespace std;




int main()
{
	unsigned long long lTarget = -4;
	short siTarget = -4;
	char szTarget[] = { -128, -4, -2, -1, 0, 1, 2, 4, 127 };
	std::string strBinaryOriginalCode;
	std::string strBinaryOriginalCodeBitSet;
	for (int i = 0; i < 9; i++)
	{
		strBinaryOriginalCode = BinaryOriginalCode(szTarget[i]);
		strBinaryOriginalCodeBitSet = BinaryOriginalCode_bitset(szTarget[i]);
		if (i == 0)
		{
			cout << ELEMTYPE(szTarget[0]) << endl
				<< TYPEID(szTarget[0]) << endl
				<< ELEMNAME(szTarget[0]) << endl << endl;
		}

		cout << "Value   = " << szTarget[i] << endl
			<< "Length  = " << strBinaryOriginalCodeBitSet.length() << endl
			<< "BinaryOriginalCode ()        ���� �� \n" << strBinaryOriginalCode << endl
			<< "BinaryOriginalCode_bitset () ���� �� \n" << strBinaryOriginalCodeBitSet << endl << endl;
	}
	system("pause");
	return 0;
}

/*
char8���ͱ������з���λ���ֵΪ2^7-1 = 127,��Сֵ 2^7 = 128;
��λʱ������λ���ƶ���
�ӵ� n-1(n = 8) λ�ÿ�ʼ��ʹ�÷���λ�����λ������1��ȡ��0����1��
һֱ�ظ��� n = 0����ʱ��δ�ƶ������λ����1 �� ȡ��0����1��


ִ�н����
elemtype: typeid  : char
typeid  : char
elemname: szTarget[0]

Value   = �
Length  = 8
BinaryOriginalCode ()        ���� ��
10000000
BinaryOriginalCode_bitset () ���� ��
10000000

Value   =
Length  = 8
BinaryOriginalCode ()        ���� ��
11111100
BinaryOriginalCode_bitset () ���� ��
11111100

Value   =
Length  = 8
BinaryOriginalCode ()        ���� ��
11111110
BinaryOriginalCode_bitset () ���� ��
11111110

Value   = �
Length  = 8
BinaryOriginalCode ()        ���� ��
11111111
BinaryOriginalCode_bitset () ���� ��
11111111

Value   =

*/