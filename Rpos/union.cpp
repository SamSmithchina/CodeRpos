/******************************************************************
* Author:	Sam Smith
* Function:   联合体 unoin 结构。，
* Time:
* Description:
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/

#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include <string>
//#include <math.h>
//#include <iomanip>



using namespace std;

enum color{red=0, green, pink=4,write, black};

union w
{
    int a;
    char b;
}c;

//https://blog.csdn.net/bitwei/article/details/6620666
//https://www.cnblogs.com/geekham/p/4227717.html
int checkCPU()      //检查机器大小端
{
    c.a = 1;
    c.b == 1;
    cout<<"C.a = "<<c.a<<"\tC.b = "<<c.b<<endl;     //神奇，
    return (c.b);
}

struct student
{
    char name[6];
    int age;
    char* GetName(void){return name;};
    int GetAge(void){return age;};
};

union score
{
    int i_sc;
    float f_sc;
    int GetInt(void){return i_sc;};
    float GetFloat(void){return f_sc;};
};

int main(void)
{
    student st_stu = {"Lubin", 27};
    score un_sc = {100};
    int i =0;

    cout << st_stu.GetName() << endl;
    cout << st_stu.GetAge() << endl;
    cout << un_sc.GetInt() << endl;
    cout<<"sizeof(char) = "<<sizeof(char )<<endl;

    cout<<"sizeof(enum) = "<<sizeof(color)<<endl;
  //  cout<<"sizeof(enum) = "<<sizeof(enum)<<endl;
    color  clr;
    clr = green;
    cout<<"clr = "<< clr<<endl;
    clr = write ;
    cout<<"clr = "<< clr<<endl;

    i = checkCPU();
    cout<<i<<endl;

    return 0;
}
