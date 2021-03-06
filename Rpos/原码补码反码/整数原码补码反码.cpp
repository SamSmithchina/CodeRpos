/*
时间： 2018-12-20 17:13:19
功能： 实现求一个int整数的原码，补码，反码
实现方法： 通过位运算得到原码， 在根据正负数的求反原理求得反码， 最后负数的补码由其加一计算得到

*/


#include <iostream>
#include <string>
#include "number binary code.h"

#define STRTYPE "elemtype: "
#define STRNAME "elemname: "
#define TYPEID(x) ("typeid  : ") << (typeid(x).name())	//	(STRTYPE)
#define ELEMNAME(x) (STRNAME) << (#x)	//	(STRNAME)
#define ELEMTYPE(x) STRTYPE<<TYPEID(x)			//不要使用C++-->预编译到文件-->选项是， 如果选是程序就会报找不到ElemType.obj文件；

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
			<< "BinaryOriginalCode ()        反码 ： \n" << strBinaryOriginalCode << endl
			<< "BinaryOriginalCode_bitset () 反码 ： \n" << strBinaryOriginalCodeBitSet << endl << endl;
	}
	system("pause");
	return 0;
}

/*
char8类型变量，有符号位最大值为2^7-1 = 127,最小值 2^7 = 128;
移位时，符号位不移动，
从第 n-1(n = 8) 位置开始，使得符号位至最低位，与上1，取其0或者1，
一直重复至 n = 0，此时数未移动，最低位与上1 ， 取其0或者1，


执行结果：
elemtype: typeid  : char
typeid  : char
elemname: szTarget[0]

Value   = �
Length  = 8
BinaryOriginalCode ()        反码 ：
10000000
BinaryOriginalCode_bitset () 反码 ：
10000000

Value   =
Length  = 8
BinaryOriginalCode ()        反码 ：
11111100
BinaryOriginalCode_bitset () 反码 ：
11111100

Value   =
Length  = 8
BinaryOriginalCode ()        反码 ：
11111110
BinaryOriginalCode_bitset () 反码 ：
11111110

Value   = �
Length  = 8
BinaryOriginalCode ()        反码 ：
11111111
BinaryOriginalCode_bitset () 反码 ：
11111111

Value   =

*/