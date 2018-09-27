//��7.8 �ڴ����к졢�ơ������ס���5����ɫ�������ɸ���ÿ�δӿڴ�������ȡ��3�����ʵõ�3�ֲ�ͬ��ɫ����Ŀ���ȡ�������ÿ�����е����
#include <iostream>
#include <iomanip>                             //�����ʱҪ�õ�setw���Ʒ�
#include <windows.h>

using namespace std;
int iSolutionSpace = 0;
int Counter = 0;
enum color { red, yellow, blue, white, black };      //����ö������color
int LENGTH = 3;

//ѭ���������
void ForCircle()
{
	color clr;                                     //����color���͵ı���clr
	int i, j, k = 0, loop;                            //iSolutionSpace���ۼƲ�ͬ��ɫ�������
	for (i = red; i <= black; i++)                       //��iΪĳһ��ɫʱ
		for (j = red; j <= black; j++)                     //��jΪĳһ��ɫʱ
			if (i != j)                                 //��ǰ���������ɫ��ͬ
			{
				for (k = red; k <= black; k++) //ֻ��ǰ���������ɫ��ͬ������Ҫ����3�������ɫ
				{
					if ((k != i) && (k != j))   //3�������ɫ����ͬ
					{
						iSolutionSpace++;                //ʹ�ۼ�ֵiSolutionSpace��1
						cout << setiosflags(ios::left) << setw(8) << iSolutionSpace;         //�����ǰ��iSolutionSpaceֵ���ֶο��Ϊ3
						for (loop = 1; loop <= 3; loop++)   //�Ⱥ��3����������
						{
							switch (loop)              //loop��ֵ�Ⱥ�Ϊ1,2,3
							{
							case 1: clr = color(i); break;  //color(i)��ǿ������ת����ʹclr��ֵΪi
							case 2: clr = color(j); break;  //ʹclr��ֵΪj
							case 3: clr = color(k); break;  //ʹclr��ֵΪk
							default:break;
							}
							switch (clr)         //�ж�clr��ֵ�������Ӧ�ġ���ɫ��
							{
							case red:    cout << setw(16) << "red"; break;
							case yellow: cout << setw(16) << "yellow"; break;
							case blue:   cout << setw(16) << "blue"; break;
							case white:  cout << setw(16) << "white"; break;
							case black:  cout << setw(16) << "black"; break;
							default:                   break;
							}
						}
						cout << endl;
					}
				}
			}
	cout << "total:" << iSolutionSpace << endl;        //���������������ϵĸ���
}

/* ���ݷ���һ���� */
#ifdef Algorithm
bool finished = FALSE; // �Ƿ���ȫ����?
backtrack(int a[], int k, data input)
{
	int c[MAXCANDIDATES];//��������ĺ�ѡ
	int ncandidates; // ��ѡ��Ŀ
	int i; // counter
	if (is_a_solution(a, k, input))
		process_solution(a, k, input);
	else {
		k = k + 1;
		construct_candidates(a, k, input, c, &ncandidates);
		for (i = 0; i < ncandidates; i++) {
			a[k] = c[i];
			make_move(a, k, input);
			backtrack(a, k, input);
			unmake_move(a, k, input);
			if (finished) return;  ���������ֹ��������ǰ�˳�
		}
	}
}
#endif

//�ݹ鷨 ���Length����� ��ϵ����п��ܣ�
int Recursive(int *iAnwser, int iLength, int *iTemp)
{

	int i = 0;
	int j = 0;

	bool RightAnwser = true;
	//�жϵ�ǰ��iAnwser[]�ǺϷ��⣬
	if (iLength == LENGTH)
	{
		for (i = 0; i < iLength; i++)
		{
			for (j = i; j < iLength; j++)
			{
				if (iAnwser[i] == iAnwser[j])	//�Ϸ�
				{
					RightAnwser = false;
				}
			}
		}
		cout << Counter++ << endl;
		if (RightAnwser)
		{
			cout << setiosflags(ios::left) << setw(10) << ++iSolutionSpace;
			for (i = 0; i < iLength; i++)
			{
				switch (iAnwser[i])
				{
				case red:    cout << setw(16) << "red"; break;
				case yellow: cout << setw(16) << "yellow"; break;
				case blue:   cout << setw(16) << "blue"; break;
				case white:  cout << setw(16) << "white"; break;
				case black:  cout << setw(16) << "black"; break;
				default:
					cout << endl;
				}
			}
			cout << endl;
		}

		return 0;
	}		//end if

	iLength++;
	//Ѱ����һ���Ŀ��ܽ�
	for (i = 0; i < 3; i++)
	{
		iAnwser[iLength] = i;
		Recursive(iAnwser, iLength,iTemp);
		iAnwser[iLength] = -1;
	}
	return 0;

}

int main()
{
	iSolutionSpace = 0;
	//	ForCircle();		///ѭ������������

	iSolutionSpace = 0;
	int  iAnwser[3];
	int iLength = -1;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		iAnwser[i] = -1;
	}
	int iTemp[10] = { 0 };
	Recursive(iAnwser, iLength, iTemp);
	system("pause");
	return 0;
}

//
