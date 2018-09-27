/* c/c++ λ���� ,
λ������У�
    &(��λ��)��|(��λ��)��^(��λ���)��~ (��λȡ��) , << (����)  �� >> (����)��
    ���У���λȡ��������ǵ�Ŀ������������Ϊ˫Ŀ�������
    λ����������ȼ��Ӹߵ��ͣ�����Ϊ~��&��^��|��
    ����~�Ľ�Ϸ����������������ȼ����������������
	����������Ľ�Ϸ������������ң������ȼ����ڹ�ϵ�������
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// char ��һ���ֽڣ����ڹ۲��ֽ�֮��λ���������

	char szLeft = '0';
	char szRight = '1';
	int iHex = 0x01;
	int iNumber[2] ={ 0x00 ,0x01 };

	cout << setw(10) << setiosflags(ios::left)
		<< "��λ�� \n"
		<< "char '0' & 'char ��1�� = " << (char)(szLeft & szRight) //�������Ҫ������ת�����//char '0' & 'char ��1�� = char(0)
        <<endl
		<< "0x01 & 0x00 = " << (iHex & iNumber[0] )
		<<endl
		<<"0x01 & 0x01 = " << (iHex & iNumber[1])
		<< endl << endl;

	cout << setw(10) << setiosflags(ios::left)
		<< "��λ�� \n"
		<< "char '0' | 'char ��1�� = " << (szLeft | szRight)
        <<endl
		<< "0x01 | 0x00 = " << (iHex | iNumber[0])
		<<endl
        <<"0x01 | 0x01 = " << (iHex | iNumber[1])
        << endl << endl;

	cout << setw(10) << setiosflags(ios::left)
		<< "��λ�� \n"
		<< "��λ�� char '0' = " << (~ szLeft)
		<<endl
		<< " ��λ�� ���롮1�� = " << (~ szRight)
		<<endl
		<< "0x01 ~ 0x00 = " << (~ iNumber[0])
		<<endl
		<<"0x01 ~ 0x01 = " << (~ iNumber[1])
        << endl << endl;

	cout << setw(10) << setiosflags(ios::left)
		<< "��λ��� \n"
		<< " char '0' ^ char '1' = " <<( szLeft ^ szRight)
		<<endl
		<< "0x01 ^ 0x00 = " << (iHex ^ iNumber[0])
		<< endl
		<< "0x01 ^ 0x01 = " << (iHex ^ iNumber[1])
		<< endl << endl;

	return 0;
}

/*��������
��λ��
  char '0' & 'char ��1�� = 48
0x01 & 0x00 = 0
0x01 & 0x01 = 1

��λ��
  char '0' | 'char ��1�� = 49
0x01 | 0x00 = 1
0x01 | 0x01 = 1

��λ��
  ��λ�� char '0' = -49
 ��λ�� ���롮1�� = -50
0x01 ~ 0x00 = -1
0x01 ~ 0x01 = -2

��λ���
 char '0' ^ char '1' = 1
0x01 ^ 0x00 = 1
0x01 ^ 0x01 = 0


Process returned 0 (0x0)   execution time : 0.028 s
Press any key to continue.


*/
