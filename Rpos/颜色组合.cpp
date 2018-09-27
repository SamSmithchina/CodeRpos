//例7.8 口袋中有红、黄、蓝、白、黑5种颜色的球若干个。每次从口袋中任意取出3个球，问得到3种不同颜色的球的可能取法，输出每种排列的情况
#include <iostream>
#include <iomanip>                             //在输出时要用到setw控制符
#include <windows.h>

using namespace std;
int iSolutionSpace = 0;
int Counter = 0;
enum color { red, yellow, blue, white, black };      //声明枚举类型color
int LENGTH = 3;

//循环输出方法
void ForCircle()
{
	color clr;                                     //定义color类型的变量clr
	int i, j, k = 0, loop;                            //iSolutionSpace是累计不同颜色的组合数
	for (i = red; i <= black; i++)                       //当i为某一颜色时
		for (j = red; j <= black; j++)                     //当j为某一颜色时
			if (i != j)                                 //若前两个球的颜色不同
			{
				for (k = red; k <= black; k++) //只有前两个球的颜色不同，才需要检查第3个球的颜色
				{
					if ((k != i) && (k != j))   //3个球的颜色都不同
					{
						iSolutionSpace++;                //使累计值iSolutionSpace加1
						cout << setiosflags(ios::left) << setw(8) << iSolutionSpace;         //输出当前的iSolutionSpace值，字段宽度为3
						for (loop = 1; loop <= 3; loop++)   //先后对3个球作处理
						{
							switch (loop)              //loop的值先后为1,2,3
							{
							case 1: clr = color(i); break;  //color(i)是强制类型转换，使clr的值为i
							case 2: clr = color(j); break;  //使clr的值为j
							case 3: clr = color(k); break;  //使clr的值为k
							default:break;
							}
							switch (clr)         //判断clr的值，输出相应的“颜色”
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
	cout << "total:" << iSolutionSpace << endl;        //输出符合条件的组合的个数
}

/* 回溯法的一般框架 */
#ifdef Algorithm
bool finished = FALSE; // 是否获得全部解?
backtrack(int a[], int k, data input)
{
	int c[MAXCANDIDATES];//这次搜索的候选
	int ncandidates; // 候选数目
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
			if (finished) return;  如果符合终止条件就提前退出
		}
	}
}
#endif

//递归法 输出Length层深度 组合的所有可能；
int Recursive(int *iAnwser, int iLength, int *iTemp)
{

	int i = 0;
	int j = 0;

	bool RightAnwser = true;
	//判断当前的iAnwser[]是合法解，
	if (iLength == LENGTH)
	{
		for (i = 0; i < iLength; i++)
		{
			for (j = i; j < iLength; j++)
			{
				if (iAnwser[i] == iAnwser[j])	//合法
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
	//寻找这一步的可能解
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
	//	ForCircle();		///循环方法输出组合

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
