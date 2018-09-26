#include <iostream> 
 #include <time.h>
 #include <stdlib.h>
 
 using namespace std;
 int main()
 {
 	srand((unsigned)time(NULL));
 	int ui64Cjjg = 1050;
				int ui64Price = ui64Cjjg - rand() %1000 ;
				for (; 900 > ui64Price || ui64Price > 1050;) //价格在跌幅 到 买一价之间	
				{
					ui64Price = ui64Cjjg - rand() % 1000;
					cout<< " ui64price = "  << ui64Price <<endl;
				}		
 	return 0;
 }
