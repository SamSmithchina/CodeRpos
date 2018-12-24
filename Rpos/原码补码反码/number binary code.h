#ifndef __NUMBER_BINARY_CODE_H__
#define __NUMBER_BINARY_CODE_H__

#include <iostream>
#include <string>
#include <bitset>
using namespace std;


//移位求原码
template<typename T>
std::string BinaryOriginalCode(T tTarget)
{
	const int iSizeT = sizeof(T) * 8; //根据传入的数位宽来循环移位
	int iPos = iSizeT - 1;
	std::string strBinaryOriginalCode = "";
	int iRes = 0;
	for (iPos; iPos >= 0; iPos--)
	{
		iRes = (tTarget >> iPos);
		iRes &= 1;
		if (iRes == 0)
		{
			strBinaryOriginalCode += "0";
		}
		else
		{
			strBinaryOriginalCode += "1";
		}

	}
	return strBinaryOriginalCode;
}

template<typename T>
std::string BinaryOriginalCode_bitset(T tTarget)
{
	//增加头文件 #include <bitset>
	//使用bitset转换二进制 

	std::bitset<sizeof(T) * 8> bitsetNUmber(tTarget);
	return (bitsetNUmber.to_string());

}

#endif