/* c/c++ 位运算 ,
位运算符有：
    &(按位与)、|(按位或)、^(按位异或)、~ (按位取反) , << (左移)  ， >> (右移)。
    其中，按位取反运算符是单目运算符，其余均为双目运算符。
    位运算符的优先级从高到低，依次为~、&、^、|，
    其中~的结合方向自右至左，且优先级高于算术运算符，
	其余运算符的结合方向都是自左至右，且优先级低于关系运算符。
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// char 是一个字节，便于观察字节之间位运算的现象；

	char szLeft = '0';
	char szRight = '1';
	int iHex = 0x01;
	int iNumber[2] ={ 0x00 ,0x01 };

	cout << setw(10) << setiosflags(ios::left)
		<< "按位与 \n"
		<< "char '0' & 'char ‘1’ = " << (char)(szLeft & szRight) //这里的需要用类型转换输出//char '0' & 'char ‘1’ = char(0)
        <<endl
		<< "0x01 & 0x00 = " << (iHex & iNumber[0] )
		<<endl
		<<"0x01 & 0x01 = " << (iHex & iNumber[1])
		<< endl << endl;

	cout << setw(10) << setiosflags(ios::left)
		<< "按位或 \n"
		<< "char '0' | 'char ‘1’ = " << (szLeft | szRight)
        <<endl
		<< "0x01 | 0x00 = " << (iHex | iNumber[0])
		<<endl
        <<"0x01 | 0x01 = " << (iHex | iNumber[1])
        << endl << endl;

	cout << setw(10) << setiosflags(ios::left)
		<< "按位非 \n"
		<< "按位非 char '0' = " << (~ szLeft)
		<<endl
		<< " 按位非 插入‘1’ = " << (~ szRight)
		<<endl
		<< "0x01 ~ 0x00 = " << (~ iNumber[0])
		<<endl
		<<"0x01 ~ 0x01 = " << (~ iNumber[1])
        << endl << endl;

	cout << setw(10) << setiosflags(ios::left)
		<< "按位异或 \n"
		<< " char '0' ^ char '1' = " <<( szLeft ^ szRight)
		<<endl
		<< "0x01 ^ 0x00 = " << (iHex ^ iNumber[0])
		<< endl
		<< "0x01 ^ 0x01 = " << (iHex ^ iNumber[1])
		<< endl << endl;

	return 0;
}

/*输出结果：
按位与
  char '0' & 'char ‘1’ = 48
0x01 & 0x00 = 0
0x01 & 0x01 = 1

按位或
  char '0' | 'char ‘1’ = 49
0x01 | 0x00 = 1
0x01 | 0x01 = 1

按位非
  按位非 char '0' = -49
 按位非 插入‘1’ = -50
0x01 ~ 0x00 = -1
0x01 ~ 0x01 = -2

按位异或
 char '0' ^ char '1' = 1
0x01 ^ 0x00 = 1
0x01 ^ 0x01 = 0


Process returned 0 (0x0)   execution time : 0.028 s
Press any key to continue.


*/
