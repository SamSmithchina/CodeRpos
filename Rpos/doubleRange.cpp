#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<iomanip>
#include<limits>
using namespace std;

int main()
{
    long long_i = LONG_MAX;
    long double  d= (long double)11223344;
    double temp;
    double fraction;
    double *iptr=NULL;
    //cout<<setprecision(13)<<"ATTENTION ! d = : "<< d <<endl; //setprecision(n)的精度n要合理，设置20就可以发现最后的精度丢失了
   // std::cout.unsetf(std::ios_base::floatfield);
    iptr = new double;
    fraction = modf(d,iptr);
    temp = *iptr;
    //cout<<"long max"<<LONG_MAX<<endl;
    //cout<<long_i<<endl;
    cout<<temp<<". "<<setprecision(10)<<fraction<<endl;//精度有问题
   // cout<<setw(20)<<setiosflags(ios::left)<<temp<<" - "<<fraction<<endl;//精度有问题
    //cout<<"long integer HIGHT: "<<temp/10000<<" LOW: "<<endl;

    d = 3.14e+2d;
    cout<<"d = : "<<d<<endl;

    d =3.14e-1;
    cout<<"d = : "<<d<<endl;

    return 0;
}
