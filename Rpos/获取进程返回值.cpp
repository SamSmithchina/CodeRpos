/****************************************************************** 
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		2018-07-16 14:23:53
* Description: 调用一个另一个exe程序，获取该程序的返回值；

* ***********************************************************************/

#include <iostream>
#include <string>
#include <Windows.h>
#include <tchar.h>

using namespace std;

int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&si, sizeof(si));

	std::string strModel = "Transform to MatchAllWithoutQuotation \n";
	TCHAR TransformCMD[142] = _T("d:\\work_program\\simutgw_win64\\simutgw_cli.exe -h 127.0.0.1 -p 50000 -f d:\\work_program\\simutgw_win64\\test_data\\cli_cmd\\cmd_matchmode_sall.txt");
	//system(TransformCMD);

	CreateProcess(NULL, TransformCMD, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &si, &pi);

	WaitForSingleObject(pi.hProcess, INFINITE);
	DWORD iDRes = 0;
	GetExitCodeProcess(pi.hProcess, &iDRes);
	if (iDRes == 0)
	{
		cout <<strModel << endl;
	}

	cin.get();
	return 0;
}