#include <iostream>

#include <cstdlib>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int  g_BenchMark = 100000;

#define NEW(personnelX)(\
	g_BenchMark++;\
	personnelX.iID = g_BenchMark - 100000;\
	personnelX.strName = itoa(iID, NULL, 10);\
	personnelX.strName.insert(0, "S.S_");\
	personnelX.iTelPhone = g_BenchMark;\
	personnelX.Display(); \
)

class Personnel
{
private:
	int iID;
	string strName;
	int iTelPhone;

public:
	void Display()
	{
		cout << setw(9) << setiosflags(ios::left) << "ID " << iID << endl;
		cout << setw(9) << setiosflags(ios::left) << "strName " << strName << endl;
		cout << setw(9) << setiosflags(ios::left) << "iTelPhone " << iTelPhone << endl;
	}

	Personnel()
	{
		g_BenchMark++;
		iID = g_BenchMark - 100000;
		strName = itoa(iID, NULL, 10);
		strName.insert(0, "S.S_");
		iTelPhone = g_BenchMark;
		Display();
	}

	~Personnel();

	Personnel operator = (Personnel perPeople)
	{
		this->iID = perPeople.iID;
		this->strName = perPeople.strName;
		this->iTelPhone = perPeople.iTelPhone;
		return *this;
	}
};

int main()
{
	map <int , class Personnel> myMap;
	
	Personnel perPeople;
	Personnel perTemp;
	//拷贝复制，覆盖原有值
	myMap[1] = perPeople;

	//insert
	myMap.insert(map<int, Personnel>::value_type(1, perTemp));
	NEW(perTemp);
	myMap.insert(pair<int, Personnel>(1, perTemp));
	return 0;
}
