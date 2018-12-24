#ifndef __NUMBER_BINARY_CODE_H__
#define __NUMBER_BINARY_CODE_H__

#include <iostream>
#include <string>
#include <bitset>
using namespace std;


//��λ��ԭ��
template<typename T>
std::string BinaryOriginalCode(T tTarget)
{
	const int iSizeT = sizeof(T) * 8; //���ݴ������λ����ѭ����λ
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
	//����ͷ�ļ� #include <bitset>
	//ʹ��bitsetת�������� 

	std::bitset<sizeof(T) * 8> bitsetNUmber(tTarget);
	return (bitsetNUmber.to_string());

}

#endif