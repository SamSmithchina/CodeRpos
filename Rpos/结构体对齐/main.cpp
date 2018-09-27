
#include <iostream>
//#pragma pack(4)
#include "myStruct.h"

//http://www.cnblogs.com/clover-toeic/p/3853132.html#

//http://www.cnblogs.com/clover-toeic/p/3853132.html#3991786
//显示指定pack(4),有效对齐值=min{自身对齐值，当前指定的pack值}。sizeof(Compound) =12
//若没指定， 有效对齐值为 自身大小，sizeof(Compound) =  16

int main()
{
    std::cout<<"string sizeof = "<<sizeof(std::string)<<std::endl;
    std::cout<<"myStruct.sizeof ="<<sizeof(SHShare)<<std::endl;
    std::cout<<"Compound.sizeof ="<<sizeof(Compound)<<std::endl;
    return 0;
}
