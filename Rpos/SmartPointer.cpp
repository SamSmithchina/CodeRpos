/******************************************************************
* Author:	Sam Smith
* Function:
* Time: ʱ��2018-07-04 17:11:00
* Description:��ϰֻ��ָ��
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include <tr1/memory>
//#include <math.h>
//#include <iomanip>

using namespace std;

tr1::shared_ptr<string> pwin;

void DisplaySmartPointer(tr1::shared_ptr<string> pwin)
{
    cout<<pwin<<endl;

}
int main()
{
    tr1::shared_ptr<string> films[5] =
    {
        tr1::shared_ptr<string> (new string("Fowl Balls")),
        tr1::shared_ptr<string> (new string("Duck Walks")),
        tr1::shared_ptr<string> (new string("Chicken Runs")),
        tr1::shared_ptr<string> (new string("Turkey Errors")),
        tr1::shared_ptr<string> (new string("Goose Eggs"))
    };

    pwin = films[2]; // films[2] loses ownership. ������Ȩ��films[2]ת�ø�pwin����ʱfilms[2]�������ø��ַ����Ӷ���ɿ�ָ��
    // pwin =nullptr;
    cout << "The nominees for best avian baseball film are\n";
    for(int i = 0; i < 5; ++i)
        cout << *films[i] << endl;
    cout << "The winner is " << *pwin << endl;
    cin.get();
    return 0;
}

/*
https://blog.csdn.net/konizhang2012/article/details/27126457
CCҪʹ��4.3.x���ϰ汾���ӱ���ѡ�-std=gnu++0x���Ϳ���ֱ����std�����ռ���ʹ�á�
��Ҫ��ʽ��ʹ��std::tr1����������ռ䱻VC9֧�֣�����VC10�Լ�GCC4.3.x������������
ͷ�ļ�ʹ�� #include <tr1/memory>
std::tr1::shared_ptr ����ʹ�ã����������İ汾�й�ϵ�ɡ�
*/
