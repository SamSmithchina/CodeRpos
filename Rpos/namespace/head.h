#ifndef __HEAD_H__
#define __HEAD_H__

#include <iostream>

class PtrClass
{
	//
	//menber
	//
	char* ptrC;

	//
	//funcation
	//
public:
	PtrClass();
	void Disp()
	{
		std::cout << "Disp()\n";
	}
	~PtrClass();
};

PtrClass::PtrClass()
{
	ptrC = new char;
	if (NULL == ptrC)
	{
		std::cout << "new pinter is failed \n";
	}
	else
	{
		*ptrC = 'C';
		std::cout << "PtrClasss() , * ptrC = " << *ptrC << std::endl;
	}
}

PtrClass::~PtrClass()
{
	std::cout << "~PtrClass() \n";
	delete ptrC;
	ptrC = NULL;
}


#endif