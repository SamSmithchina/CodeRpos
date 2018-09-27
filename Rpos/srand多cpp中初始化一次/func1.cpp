#include "mysrand.h"

using namespace std;

void func1()
{
    int i = 1;
    srand(time(NULL));
    for (i = 0; i< 10; i++)
    {
        cout << i << "\t" << rand()%1000 << endl;
    }
    cout << endl << "fun1 ( ) finished! " << endl << endl ;
}
