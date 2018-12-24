
#ifndef __ELEMENTTYPE_H__
#define __ELEMENTTYPE_H__


// 用宏定义展开变量类型和变量名
//(1) 当宏中有#运算符时，参数不再被展开；
//(2) 当宏中有##运算符时，则先展开函数，再展开里面的参数；

#define STRTYPE "elemtype: "
#define STRNAME "elemname: "
#define TYPEID(x) (typeid(x).name())	//	(STRTYPE)
#define ELEMNAME(x) (STRNAME) << (#x)	//	(STRNAME)
#define ELEMTYPE(x) STRTYPE<<TYPEID(x)			//不要使用C++-->预编译到文件-->选项是， 如果选是程序就会报找不到ElemType.obj文件；

template<class T>
void CalcElementSize(T tElem)
{
	long long llmax = 0;
	long long llmin = 0;

	std::cout << ELEMTYPE(tElem) << std::endl;
	std::cout << "sizeof(tElem) : " << sizeof(tElem) << std::endl;

	std::cout << "max number :    " << std::numeric_limits<T>::max() << std::endl;
	std::cout << "min number :    " << std::numeric_limits<T>::min() << std::endl;

	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - \n";
}

#endif


//union 联合体的使用；

//	#PREX".%d\n", ival;