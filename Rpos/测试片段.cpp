#include <iostream> 
 #include <time.h>
 #include <stdlib.h>
 
 using namespace std;
 int main()
 {
 	srand((unsigned)time(NULL));
 	int ui64Cjjg = 1050;
				int ui64Price = ui64Cjjg - rand() %1000 ;
				for (; 900 > ui64Price || ui64Price > 1050;) //�۸��ڵ��� �� ��һ��֮��	
				{
					ui64Price = ui64Cjjg - rand() % 1000;
					cout<< " ui64price = "  << ui64Price <<endl;
				}		
 	return 0;
 }
