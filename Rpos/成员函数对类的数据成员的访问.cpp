#include<iostream>

using namespace std;

class myclass
{
private:
    int idata;
public:
    myclass(int a):idata(a){};
    myclass(){idata = 10;};
    ~myclass();
    void Modify();
    void Show();

};

myclass::~myclass()
{
    cout<<"~myclass()"<<endl;

}

void myclass::Modify()
{
    cout<<"Modify()"<<endl;
    idata ++;
}

void myclass::Show()
{
    cout<<"idata : "<<idata<<endl;
}

int main()
{
    myclass mc;
    mc.Show();

    mc.Modify();
    mc.Show();

    mc.~myclass();
    return 0;
}
