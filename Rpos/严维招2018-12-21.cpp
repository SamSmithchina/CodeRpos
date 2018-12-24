#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define uint16_t unsigned short

static void SeekIkeyEnable_Process(void)
{
	unsigned char* SeekKey_Answer = false;
	static uint16_t SeekKey_NextTime = 0u;
	bool StartButtonSeekIkey_Enable = true;
	if (SeekKey_NextTime != 0u)
	{
		SeekKey_NextTime--;
	}

	if (StartButtonSeekIkey_Enable == true)
	{
		cout << "ok " << endl;
	}
}

int main()
{
	SeekIkeyEnable_Process();
	return 0;
}