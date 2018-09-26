/******************************************************************
* Author:
* Function:将一个整数的个十百千等位置上每一位分离
* Time:2018-05-14 15:16:41
* Description:
* Calls:
* Called By:
* Input:
* Output:
* *******************************************************************/

#include<iostream>
#include<vector>
#include<windows.h>
#include<math.h>

using namespace std;
long MAX_NUMBER = 0;
enum PositiveAndNegativeFlag {positive, negative};//设置正负标志位
//enum Parity{odd, even };

int main()
{
    int i = 0, j = 0 ,k = 0;
    vector<int> v;
    vector<int>::iterator it;
    PositiveAndNegativeFlag flag;
    int index =0;
    int temp=0;

    //int
    cout<<"please enter your number:"<<endl;
    cin>>MAX_NUMBER;
    temp = MAX_NUMBER;
    //区分正负数
    if(temp < 0)
    {
        temp = labs(temp);
        flag = negative;
    }
    else flag = positive; //0 也会当作正数
    //Mod模除分离每一位

    for(temp ; temp>10;)
    {
        index = temp % 10;
        v.push_back(index);

        temp = temp / 10;
    }
    v.push_back(temp);

    //显示正负性
    cout<<"P&N Flag: "<<flag*(-1)<<endl;
    //小端从低位到高位显示数的每一位
    for(it= v.begin();it!=v.end();it++)
    {
        cout<<*it<<"  ,  ";
    }

    //system("pause");
    return 0;
}
