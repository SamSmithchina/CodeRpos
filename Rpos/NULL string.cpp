#include <iostream>
#include <string>
using namespace std;
int main() {
	try 
	{
		std::string strTemp = NULL;
		strTemp = " initialized now !";
		cout << "NULL string " << "\t" << strTemp <<endl;
	}
	catch(std::exception& e)
	{
		throw(e);
	}
	system("pause");
	return 0;
}

/*
terminate called after throwing an instance of 'std::exception'
  what():  std::exception

This application has requested the Runtime to terminate it in an unusual way.
Please contact the application's support team for more information.

--------------------------------
Process exited after 1.259 seconds with return value 3
请按任意键继续. . .
请按任意键继续. . .
*/
