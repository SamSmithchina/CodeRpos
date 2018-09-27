/*
author: sam smith ;
time ； 2018-07-31 17:51:38
function; 了解or循环中多个判断语句，如果中间某条语句不通过， 后续循环是否会执行
*/


#include <iostream>

using namespace std;

int main()
{
    int a[5] = { 0,1,2,2,4 };
    int b[5] =  { 1,2,3,4,5 };
    int i = 0;

     for( i = 0; i == a[i] && i< 5; i++)
     {

         cout<<"b[ "<<i<<" ] = "<< b[i] <<endl;
     }
    return 0;
}

/*
输出：
b[ 0 ] = 1
b[ 1 ] = 2
b[ 2 ] = 3

结论： 在循环体中间判断条件不成立，循环将会终止

*/
