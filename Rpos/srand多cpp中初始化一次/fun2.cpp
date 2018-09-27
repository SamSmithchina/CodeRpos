#include "mysrand.h"

using namespace std;
void func2()
{
    int i = 1;
    for (i = 0; i< 10; i++)
    {
        cout << i << "\t" << rand()%1000 << endl;
    }
    cout << endl << "fun2 ( ) finished! " << endl << endl ;
}
