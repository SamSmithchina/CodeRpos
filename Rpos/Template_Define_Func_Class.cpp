/******************************************************************
* Author: sam
* Function: use template  in define or function or class
* Time: 2018-05-30 09:43:58
* Description:
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/

#include<iostream>
#include<stdlib.h>
#include<iomanip>

//宏模板 宏定义
#define DEF_MACRO(x) x++
#define STRING(x) #x

using namespace std;

//函数模板
template <class C1, class C2>
void myMin(C1 t1, C2 t2 )
{
    cout<<"sizeof(type): "<<sizeof(t1)<<"\t.\t"<<sizeof(t2)<<endl;
    cout<<"( "<<t1<<" . "<<t2<<" )"<<endl;
    cout<<"the  min one is: "<<(t1>t2?t2:t1)<<endl<<endl;

}

//类模板
template <typename T1, typename T2>
class myClass
{
private:
    T1 t1;
    T2 t2;

public:
    myClass(){t1 = (T1)(0.0),t2 = (T2)(0.0);}
    myClass(T1 a, T2 b):t1(a), t2(b)
    {
        cout<<"T1: "<<t1<<"\tT2: "<<t2<<endl;
    }
    void myMax(){cout<<"max num is: "<< (t1>t2?t1:t2)<<endl;}
};

int main()
{
    int a =0;
    double d =3.3;
    int intT1, intT2;

   // template <float T1, float T2>
   cout<<"Class template "<<endl;
    myClass<int,double> myC(a, d);
      myC.myMax();

   cout<<"#define STRING(): "<<STRING(iniT)<<endl;

    intT1 = a;
    cout<<"#define DEF_MACRO( a: "<<a<<"  )"<<endl;
    DEF_MACRO(a);
    intT2 = a;
    cout<<"a: "<<a<<endl;

    cout<<" function template : "<<endl;
    myMin(intT1,intT2);
    myMin(2.3 , 38.9);
    myMin(float(5.5), float(5.2));
    return 0;
}
