/******************************************************************
* Author：Sam Smith   Email:wangbingzong@szkindom.com
* Time:		 2018-07-16 11:03:38
* Description: 练习使用多线程的并发、并行、调度、休眠、锁；

* ***********************************************************************/

//使用锁；
//使用sleep阻塞进程，交出cpu

//https://www.cnblogs.com/iTlijun/p/5860379.html
//https://blog.csdn.net/kingsir2020/article/details/52264305

//线程同步
//https://www.cnblogs.com/jzincnblogs/p/5188051.html

#include <iostream>
#include <stdlib.h>
#include <mutex>
#include <Windows.h>
#include <thread>


using namespace std;

mutex mTest;
unsigned long ulCounter = 7;

void t1()
{
	while(1) 
	{
	//	Sleep(50);
		mTest.lock();

		if (ulCounter >= 15)
		{
			//mTest.lock();
			//	cout << "this_thread::get_id()" << this_thread::get_id();
			cout << "\n t1 ulCounter " << --ulCounter << endl;
			//	cin.get();
			//mTest.unlock();
		}
		mTest.unlock();
	}
}

void t2()
{
	while(1)
	{
	//	Sleep(50);
		mTest.lock();
		if (ulCounter < 10)
		{

			//	cout << "this_thread::get_id()" << this_thread::get_id();
			//this_thread::sleep_for();
			cout << "\n t2 ulCounter " << ++ulCounter << endl;
			Sleep(0);
			//	cin.get();

		}
			mTest.unlock();

	}
}

void t3()
{
	while (1)// (ulCounter < 10)
	{
		mTest.lock();
		if (ulCounter > 8 )
		{
		//	mTest.lock();
			//	cout << "this_thread::get_id()" << this_thread::get_id();
			//this_thread::sleep_for();
			cout << "\n t3 ulCounter " << ++ulCounter << endl;
			//	cin.get();
		//	mTest.unlock();
		}
		mTest.unlock();

	}
}

int main()
{

	//thread thTest1(t1);//
	thread thTest2(t2);
	thread thTeset(t3);
	thread thTest1(t1);


	thTest1.join();		//等待主线程结束
	thTest2.join();
	thTeset.join();

	//thTest1.detach();
	//thTest2.detach();
	cin.get();

	return 0;
}
