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
	int i =0;
	int iMaxRound = 1000000;
    //����һ �� str.replace()
	time_t tBegin =clock();
	{
	  for(i =0; i< iMaxRound ; i++)
    	{
    		strSource = "J000000000";
    		strRes = strSource.replace(strSource.length() - strAlternate.length() , strAlternate.length(), strAlternate);
		}
	}
	time_t tEnd = clock();
	cout << strRes << endl;
	cout << "replace() ת�� "  << iMaxRound << " �� �� ��ʱ �� " << tEnd -tBegin << endl;


	//������
	tBegin =clock();
	{

    	for(i =0; i< iMaxRound ; i++)
   	  	{

    		strSource = "J000000000";
    		strSource.erase(strSource.length()-strAlternate.length(), strAlternate.length());
    		strRes = strSource + strAlternate;
    	}
	}
	tEnd =clock();
	cout<<strRes<<endl;
	cout << "erase() operator+ ת�� "  << iMaxRound << " �� �� ��ʱ �� " << tEnd -tBegin << endl;
	
	//������
	tBegin =clock();
	{
		for(i =0 ; i < iMaxRound ; i++)
		{
			strSource = "J" + strAlternate;
			strRes = strSource.insert(1 ,  9-strSource.length(), '0');
		}
	}
	tEnd =clock();
	cout<<strRes<<endl;
	cout << "erase() operator+ ת�� "  << iMaxRound << " �� �� ��ʱ �� " << tEnd -tBegin << endl;

	return 0;
}

/*
J000009876
replace() ת�� 1000000 �� �� ��ʱ �� 136
J000009876
erase() operator+ ת�� 1000000 �� �� ��ʱ �� 164
J00009876
erase() operator+ ת�� 1000000 �� �� ��ʱ �� 329

--------------------------------
Process exited after 0.6512 seconds with return value 0
�밴���������. . .

*/
