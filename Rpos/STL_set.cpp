//熟悉STL set容器的使用；

#include <iostream>
#include <set>
#include <cstdlib>
#include <string>

using namespace std;

class Url
{
public:
	int webId;
	string webName;

	Url(int i, string strTemp):webId(i), webName(strTemp){}
	
	Url()
	{
		webId = 0;
		webName = "";
	}

	friend ostream& operator <<(ostream& out, const Url urlInput)
	{
		out << "urlInput.webId : " << urlInput.webId << "\t" 
			<< "urlInput.webName : " << urlInput.webName << endl;
		return out;
	}
};
int  main()
{
	set<int, Url> mySet;
	int i = 0;
	char ch[21] = { "\0" };
	string strTemp = "";
	Url urlTemp;

	for (i = 0; i < 10; i++)
	{
		strTemp = itoa(i, ch, 10);
		urlTemp(i, strTemp);

		strTemp.insert(0, "s.s_set_");
		mySet.insert(i,urlTemp);
	}

	return 0;
}