#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//�滻Ŀ�괮ָ��λ��֮����ַ�
int main()
{
	string strSource = "J000000000";
	string strAlternate = "9876";
	string strRes;
	int i = 0;
	int iLen = 0;
	int iMaxRound = 9000000;

	cout << "ѭ������ �� " << iMaxRound << endl;

	//����һ �� str.replace()
	time_t tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			strSource = "J000000000";
			strSource.replace(strSource.length() - strAlternate.length(), strAlternate.length(), strAlternate);
		}
	}
	time_t tEnd = clock();
	cout << strSource << endl;
	cout << "����һ replace() ת�� " << iMaxRound << " �� �� ��ʱ �� " << tEnd - tBegin << endl;


	//������
	tBegin = clock();
	{

		for (i = 0; i < iMaxRound; i++)
		{

			strSource = "J000000000";
			strSource.erase(strSource.length() - strAlternate.length(), strAlternate.length());
			strSource += strAlternate;
		}
	}
	tEnd = clock();
	cout << strSource << endl;
	cout << "������ erase() operator+ ת�� " << iMaxRound << " �� �� ��ʱ �� " << tEnd - tBegin << endl;

	//������
	tBegin = clock();
	{
		for (i = 0; i < iMaxRound; i++)
		{
			strSource = "J";
			iLen = strAlternate.length();
			switch (iLen)
			{
			case 1:
				strSource += "00000000";
				break;
			case 2:
				strSource += "0000000";
				break;
			case 3:
				strSource += "000000";
				break;
			case 4:
				strSource += "00000";
				break;
			case 5:
				strSource += "0000";
				break;
			case 6:
				strSource += "000";
				break;
			case 7:
				strSource += "00";
				break;
			case 8:
				strSource += "0";
				break;
			default:
				break;
			}
			strSource += strAlternate;
		}
	}
	tEnd = clock();
	cout << strSource << endl;
	cout << "������ operator+ ת�� " << iMaxRound << " �� �� ��ʱ �� " << tEnd - tBegin << endl;

	return 0;
}

/*
ѭ������ �� 9000000
J000009876
����һ replace() ת�� 9000000 �� �� ��ʱ �� 1764
J000009876
������ erase() operator+ ת�� 9000000 �� �� ��ʱ �� 2170
J000009876
������ operator+ insert() ת�� 9000000 �� �� ��ʱ �� 3059


*/
