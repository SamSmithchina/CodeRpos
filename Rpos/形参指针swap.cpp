#include<iostream>
using namespace std;
void swap (int * pm,int * pn)
{
int *tmp = pm;//
pm =pn;
pn=tmp;
//*pm =*pn;
//*pn=*tmp;
}

int main()
{int m=4,n=3;
int * pm=& m;
int *pn=& n;
swap(pm,pn);
cout<<*pm<<","<<*pn<<endl;
return 0;
}
//为什么输出还是4,3。以为是3,4，很不解。

/*
在C中，所有的形参在接受实参时都是拷贝，即是”值“传递，所以在函数中对”值“所做的任何操作都不会影响原来的变量。
有人认为指针传递能“影响原来的值”，这不仅是误会，而且大错特错——其实在被调函数中对指针的任何操作都不会影响原来的指针值，
只有对“指针指向的内容”操作，才会永久改变指针所指向的变量值。
具体地说，如果形参指针p是由原调函数里的指针a拷贝过来的，那么函数对p的任何操作都不会影响a，而只有对*p(指针p指向的内容)的操作，才会影响到a指向的内容*a。
这一点好多初学朋友并没有真正搞清楚。
*/
