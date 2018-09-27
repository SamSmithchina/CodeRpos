//ʵ��KMP�㷨�� ����KMP�㷨���ַ���ƥ��ĸ�Чԭ��

#include <iostream>
#include <string>


using namespace std;

//����ƥ���ַ�������ø��ַ����ڵ�ǰ�ַ�λ��jʱ����һ��Ҫƥ���ƶ����ַ���k ; next[j] =k;
// @input:
//		strAdapt, ƥ���ַ���
//	@output 
//		�����ǰƥ�䴮�����ͬ�Ӵ����ȣ����´��ƶ��ַ�����λ��K������������ Next[]
int* KMP_Next(string strAdapt)
{
	int *iNext = new int[strAdapt.length()];

	iNext[0] = 0;
	int j = 1;
	int k = 0;
	cout << "Next[] {  0\t";
	while (j < (int)strAdapt.length() )
	{
		while (k > 0 && strAdapt.at(k) != strAdapt.at(j))
		{
			k = iNext[k - 1];
		}
		if (strAdapt.at(k) == strAdapt.at(j))
		{
			k++;
		}
	
		iNext[j++] = k;
		cout << k << "\t";
	}
	cout << " }" << endl;

	delete[] iNext;
}

//KMP�㷨��strAdapt�ַ��� �� strTarget�ַ��� ����ƥ�䣬
//�����ַ���ƥ����strAdapt������Ŀ�괮stTargetƥ�䣬ʱ�临�Ӷ���O��Length(strTarget)* length(strAdapt));
//KMP�㷨˼����ƥ�䴮�����д�ͷ����ʼ���Ӵ�strHeadSub�������м�λ�õ��Ӵ�strAnotherSub��ͬ���´�ƥ�䴮���ƶ�����ͬ�Ӵ�strAmotherSub����,
//��Ҫ��KMP_Next��)����������ƥ�䴮��ͬλ�õ�����ƥ���Ӵ����ȣ����Ⱦ�����һ�ƶ���λ�ã�
//@input��
//		strAdapt ƥ�䴮
//		strTarget Ŀ�괮
//@output :
//		iPosition ����ƥ�䴮��һ��ƥ��Ŀ�괮��λ�ã� ���ʼ�ղ�ƥ�䣬 �����-1��
int KMP(string strAdapt, string strTarget)
{
	int iTargetPos = 0;
	int iAdaptPos = 0;
	
	int iAdaptLength = strAdapt.length();	//ע��������Խ�磬���÷��ʷ�Χ
	int *iNext = NULL;

	cout << "Ŀ�괮 �� " << strTarget << endl;
	cout << "ƥ�䴮 �� " << strAdapt << endl;

	if (strAdapt.length() == 0 || strTarget.length() == 0)
	{
		cout << "�ַ���Ϊ�գ��޷�����ƥ������� \n" << endl;
		exit(0);
	}

	iNext = KMP_Next(strAdapt);
	for (iTargetPos = 0,iAdaptPos = 0; iTargetPos <= (int)strTarget.length(); iTargetPos++ )
	{
		while(iAdaptPos > 0 && strAdapt[iAdaptPos] != strTarget[iTargetPos])
		{
			iAdaptPos = iNext[iAdaptPos];
		}
		if (strAdapt[iAdaptPos] == strTarget[iTargetPos])
		{
			iAdaptPos++;
		}
		if (iAdaptLength == iAdaptPos)
		{
			cout << "KMP �ҵ�Ŀ�괮ƥ����ƥ�䴮����βλ�� " << iTargetPos << endl;
			return iTargetPos;
		}

		
	}
	
	delete[] iNext;
	return -1;
}

int main()
{
	string strTarget = "ABCDEFGABCDHIJKABCABCDLMNABCDEFOPQRSTUVWXYZ";
	string strAdapt = "ABCDHIJKABCABCD";

	cout << "KMP �� " << KMP(strAdapt, strTarget) << std::endl;
	system("pause");
	return 0;
}
