#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <time.h>

#define MSC_VER  -1

using namespace std;

//在simutgw工程tool_string文件夹sof_string文件中定义整数到字符串string的转换函数；代码如下
// 两位数的预制字符串
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

//使用位运算很精妙
std::string& itostr(int n, std::string& s) {
	if (n == 0) {
		s = "0";
		return s;
	}

	int sign = -(n < 0);    //判断正负性；
	int temp = n^sign;      //按位异或运算；
	unsigned int val = temp - sign;  //绝对值

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
	if (sign) {//负数符号位
		*c = '-';
	}

	c += size - 1;  //指针地址S[0],，负数偏移size位到最低位，正数偏移size-1也到最低位
	while (val >= 100) {
		int pos = val % 100;
		val /= 100;
		*(short*)(c - 1) = *(short*)(digit_pairs + 2 * pos); //用2位的short类型来一次转换2位数字，也可以用char来转换每1位
		c -= 2; //指针向高位移动两位
	}
	while (val > 0) { //数字不满2位，
		*c-- = '0' + (val % 10); //用char来转换每一位
		val /= 10;
	}
	return s;
}

int main()
{
	//测试上述的sof_string文件 itostr()函数与string类 str新能
	//c 方法
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
	cout << "itoa（） 耗时 ： " << (tEnd - tBegin) * 1000 / CLOCKS_PER_SEC << " ms" << endl;

	//c++ string 类函数to_string（）
	tBegin = clock();
	for (i = 0; i < iRound; i++)
	{
		strRes = to_string(i);
	}
	tEnd = clock();
	cout << "to_string（） 耗时 ： " << (tEnd - tBegin) * 1000 / CLOCKS_PER_SEC << " ms" << endl;

#endif // MSC_VER


	//上述 sof_string文件 itostr() 
	tBegin = clock();
	for (i = 10; i < 15; i++)
	{
		strRes.clear();
		itostr(-1 * i, strRes);
		cout << strRes << endl;
	}
	tEnd = clock();
	cout << "sof_string.itostr（） 耗时 ： " << (tEnd - tBegin) * 1000 / CLOCKS_PER_SEC << " ms" << endl;

	system("pause");
	return 0;
}

/*执行结果： sof_string.itostr() 效果很好
itoa（） 耗时 ： 593 ms
to_string（） 耗时 ： 2624 ms
sof_string.itostr（） 耗时 ： 205 ms
请按任意键继续. . .
*/