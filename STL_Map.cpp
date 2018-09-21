#include <iostream>

#include <cstdlib>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int  g_BenchMark = 100000;

//#define NEW(personnelX)(\
//	g_BenchMark++;\
//	personnelX.iID = g_BenchMark - 100000;\
//	personnelX.strName = itoa(iID, NULL, 10);\
//	personnelX.strName.insert(0, "S.S_");\
//	personnelX.iTelPhone = g_BenchMark;\
//	personnelX.Display(); \
//)

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
		//	g_BenchMark++;
		char ch[21] = { "\0" };
		iID = g_BenchMark - 100000;
		strName = itoa(iID, ch, 10);
		strName.insert(0, "S.S_");
		iTelPhone = g_BenchMark;
		Display();
	}

	//~Personnel();

	Personnel operator = (Personnel perPeople)
	{
		this->iID = perPeople.iID;
		this->strName = perPeople.strName;
		this->iTelPhone = perPeople.iTelPhone;
		return *this;
	}

	friend ostream& operator <<(ostream& out, const Personnel per)
	{
		cout << setw(5) << setiosflags(ios::left) << "ID " << setw(5) << setiosflags(ios::left) << per.iID;
		cout << setw(10) << setiosflags(ios::left) << "strName " << setw(20) << setiosflags(ios::left) << per.strName;
		cout << setw(10) << setiosflags(ios::left) << "iTelPhone " << setw(20) << setiosflags(ios::left) << per.iTelPhone << endl;
		return out;
	}

	Personnel New()
	{
		g_BenchMark++;
		iID = g_BenchMark - 100000;
		char ch[21] = { "\0" };
		strName = itoa(iID, ch, 10);
		strName.insert(0, "S.S_NEW_");
		iTelPhone = g_BenchMark;
		return *this;
	}
};

int main()
{
	int i = 0;
	map <int, class Personnel> myMap;
	Personnel perTemp;

	//insert
	myMap.insert(map<int, Personnel>::value_type(0, perTemp));
	perTemp = perTemp.New();
	myMap.insert(pair<int, Personnel>(1, perTemp));

	//�жϲ����Ƿ�����
	pair<map<int, Personnel>::iterator, bool> mapPair;
	for (i = 2; i < 10; i++)
	{
		perTemp = perTemp.New();
		myMap.insert(map<int, Personnel>::value_type(i, perTemp));
	}
	//insert �������ƣ�����ԭ��ֵ
	perTemp = perTemp.New();
	myMap[10] = perTemp;

	//ǰ�������
	cout << "ǰ�������" << endl;
	map<int, Personnel>::iterator mapIter;
	for (mapIter = myMap.begin(); mapIter != myMap.end(); mapIter++)
	{
		//���������
		cout << "map [" << mapIter->first << "] :" << endl
			<< mapIter->second << endl;
	}

	cout << "map.size( ) : " << myMap.size() << endl;
	cout << "map.max_size( ) : " << myMap.max_size() << endl;

	cout << "map.empty( ) : " << myMap.empty() << endl;

	mapIter = myMap.find(10);
	cout << "iterator = map.find(10) : " << mapIter->first << endl;

	mapIter = myMap.end();
	--mapIter;
	--mapIter;
	myMap.erase(mapIter, ++mapIter);	//����ҿ�
	try
	{
		--mapIter;
		myMap.erase(mapIter);			//����erase( )��ʽ
	}
	catch (exception* e)
	{
		throw(e);
	}
	myMap.erase(9);

	mapIter = myMap.lower_bound(3);
	cout << "iterator = map.lower_bound(3) : " << mapIter->first << endl;
	mapIter = myMap.upper_bound(4);
	cout << "iterator = map.upper_bound(4) : " << mapIter->first << endl;
	pair<map<int, Personnel>::iterator, map<int, Personnel>::iterator>mapERPair;
	mapERPair = myMap.equal_range(5);
	cout << "map.equal_range(5)=>lower_bound(5) : " << mapERPair.first->first << endl;
	cout << "map.equal_range(5)=>upper_bound(5) : " << mapERPair.second->first << endl;

	//���������
	cout << "ɾ��map�������Ԫ�أ�" << endl;
	cout << "��������� �� " << endl;
	map<int, Personnel>::reverse_iterator mapRevIter;
	for (mapRevIter = myMap.rbegin(); mapRevIter != myMap.rend(); mapRevIter++)
	{
		cout << "map [" << mapRevIter->first << "] :" << endl
			<< mapRevIter->second;
	}
	system("pause");
	return 0;
}
