#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <time.h>

#define MSC_VER  -1

using namespace std;

//��simutgw����tool_string�ļ���sof_string�ļ��ж����������ַ���string��ת����������������
// ��λ����Ԥ���ַ���
static const char digit_pairs[201] = {
	"00010203040506070809"
	"10111213141516171819"
	"20212223242526272829"
	"30313233343536373839"
	"40414243444546474849"
	"50515253545556575859"
	"60616263646566676869"
	"70717273747576777879"
	"80818283848586878889"
	"90919293949596979899"
};

//ʹ��λ����ܾ���
std::string& itostr(int n, std::string& s) {
	if (n == 0) {
		s = "0";
		return s;
	}

	int sign = -(n < 0);    //�ж������ԣ�
	int temp = n^sign;      //��λ������㣻
	unsigned int val = temp - sign;  //����ֵ

	int size;
	if (val >= 10000) {
		if (val >= 10000000) {
			if (val >= 1000000000) {
				size = 10;
			}
			else if (val >= 100000000) {
				size = 9;
			}
			else {
				size = 8;
			}
		}
		else {
			if (val >= 1000000) {
				size = 7;
			}
			else if (val >= 100000) {
				size = 6;
			}
			else {
				size = 5;
			}
		}
	}
	else {
		if (val >= 100) {
			if (val >= 1000) {
				size = 4;
			}
			else {
				size = 3;
			}
		}
		else {
			if (val >= 10) {
				size = 2;
			}
			else {
				size = 1;
			}
		}
	}
	size -= sign;
	s.resize(size);
	char* c = &s[0]; 
	if (sign) {//��������λ
		*c = '-';
	}

	c += size - 1;  //ָ���ַS[0],������ƫ��sizeλ�����λ������ƫ��size-1Ҳ�����λ
	while (val >= 100) {
		int pos = val % 100;
		val /= 100;
		*(short*)(c - 1) = *(short*)(digit_pairs + 2 * pos); //��2λ��short������һ��ת��2λ���֣�Ҳ������char��ת��ÿ1λ
		c -= 2; //ָ�����λ�ƶ���λ
	}
	while (val > 0) { //���ֲ���2λ��
		*c-- = '0' + (val % 10); //��char��ת��ÿһλ
		val /= 10;
	}
	return s;
}

int main()
{
	//����������sof_string�ļ� itostr()������string�� str����
	//c ����
	int iTemp = 0;
	int i = 0;
	int iRound = 10000;
	char szTemp[10] = { "\0" };
	string strRes;
	time_t tEnd;
	time_t tBegin;

#if MSC_VER > 0
	tBegin = clock();
	{
		for (i = 0; i < iRound; i++)
		{
			_itoa_s(i, szTemp, 10);
			strRes = szTemp;
		}
	}
	tEnd = clock();
	cout << "itoa���� ��ʱ �� " << (tEnd - tBegin) * 1000 / CLOCKS_PER_SEC << " ms" << endl;

	//c++ string �ຯ��to_string����
	tBegin = clock();
	for (i = 0; i < iRound; i++)
	{
		strRes = to_string(i);
	}
	tEnd = clock();
	cout << "to_string���� ��ʱ �� " << (tEnd - tBegin) * 1000 / CLOCKS_PER_SEC << " ms" << endl;

#endif // MSC_VER


	//���� sof_string�ļ� itostr() 
	tBegin = clock();
	for (i = 10; i < 15; i++)
	{
		strRes.clear();
		itostr(-1 * i, strRes);
		cout << strRes << endl;
	}
	tEnd = clock();
	cout << "sof_string.itostr���� ��ʱ �� " << (tEnd - tBegin) * 1000 / CLOCKS_PER_SEC << " ms" << endl;

	system("pause");
	return 0;
}

/*ִ�н���� sof_string.itostr() Ч���ܺ�
itoa���� ��ʱ �� 593 ms
to_string���� ��ʱ �� 2624 ms
sof_string.itostr���� ��ʱ �� 205 ms
�밴���������. . .
*/