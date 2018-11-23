#include <iostream>
#include <string>
using namespace std;
#define CharaLength 300

int main()
{
	char szTemp[CharaLength] = { "\0" };
	for (int i = 0; i < CharaLength; i++)
	{
		szTemp[i] = i % 256;
		cout << "|" << i << "-" << szTemp[i] << "    ";
		if (0 == i % 10)
		{
			cout << endl;
		}
	}
	system("pause");
	return 0;
}