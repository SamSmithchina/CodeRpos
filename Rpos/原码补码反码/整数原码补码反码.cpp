/*
Ê±¼ä£º 2018-12-20 17:13:19
¹¦ÄÜ£º ÊµÏÖÇóÒ»¸öintÕûÊıµÄÔ­Âë£¬²¹Âë£¬·´Âë
ÊµÏÖ·½·¨£º Í¨¹ıÎ»ÔËËãµÃµ½Ô­Âë£¬ ÔÚ¸ù¾İÕı¸ºÊıµÄÇó·´Ô­ÀíÇóµÃ·´Âë£¬ ×îºó¸ºÊıµÄ²¹ÂëÓÉÆä¼ÓÒ»¼ÆËãµÃµ½

*/


#include <iostream>
#include <string>
#include "number binary code.h"

#define STRTYPE "elemtype: "
#define STRNAME "elemname: "
#define TYPEID(x) ("typeid  : ") << (typeid(x).name())	//	(STRTYPE)
#define ELEMNAME(x) (STRNAME) << (#x)	//	(STRNAME)
#define ELEMTYPE(x) STRTYPE<<TYPEID(x)			//²»ÒªÊ¹ÓÃC++-->Ô¤±àÒëµ½ÎÄ¼ş-->Ñ¡ÏîÊÇ£¬ Èç¹ûÑ¡ÊÇ³ÌĞò¾Í»á±¨ÕÒ²»µ½ElemType.objÎÄ¼ş£»

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
			<< "BinaryOriginalCode ()        ·´Âë £º \n" << strBinaryOriginalCode << endl
			<< "BinaryOriginalCode_bitset () ·´Âë £º \n" << strBinaryOriginalCodeBitSet << endl << endl;
	}
	system("pause");
	return 0;
}

/*
char8ÀàĞÍ±äÁ¿£¬ÓĞ·ûºÅÎ»×î´óÖµÎª2^7-1 = 127,×îĞ¡Öµ 2^7 = 128;
ÒÆÎ»Ê±£¬·ûºÅÎ»²»ÒÆ¶¯£¬
´ÓµÚ n-1(n = 8) Î»ÖÃ¿ªÊ¼£¬Ê¹µÃ·ûºÅÎ»ÖÁ×îµÍÎ»£¬ÓëÉÏ1£¬È¡Æä0»òÕß1£¬
Ò»Ö±ÖØ¸´ÖÁ n = 0£¬´ËÊ±ÊıÎ´ÒÆ¶¯£¬×îµÍÎ»ÓëÉÏ1 £¬ È¡Æä0»òÕß1£¬


Ö´ĞĞ½á¹û£º
elemtype: typeid  : char
typeid  : char
elemname: szTarget[0]

Value   = €
Length  = 8
BinaryOriginalCode ()        ·´Âë £º
10000000
BinaryOriginalCode_bitset () ·´Âë £º
10000000

Value   =
Length  = 8
BinaryOriginalCode ()        ·´Âë £º
11111100
BinaryOriginalCode_bitset () ·´Âë £º
11111100

Value   =
Length  = 8
BinaryOriginalCode ()        ·´Âë £º
11111110
BinaryOriginalCode_bitset () ·´Âë £º
11111110

Value   = ÿ
Length  = 8
BinaryOriginalCode ()        ·´Âë £º
11111111
BinaryOriginalCode_bitset () ·´Âë £º
11111111

Value   =

*/