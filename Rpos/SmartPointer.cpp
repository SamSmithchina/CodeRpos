/******************************************************************
* Author:	Sam Smith
* Function:
* Time: 时间2018-07-04 17:11:00
* Description:练习只能指针
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

    pwin = films[2]; // films[2] loses ownership. 将所有权从films[2]转让给pwin，此时films[2]不再引用该字符串从而变成空指针
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
CC要使用4.3.x以上版本，加编译选项：-std=gnu++0x，就可以直接在std命名空间内使用。
不要显式的使用std::tr1，这个命名空间被VC9支持，但被VC10以及GCC4.3.x以上所抛弃！
头文件使用 #include <tr1/memory>
std::tr1::shared_ptr 可以使用，跟编译器的版本有关系吧。
*/
