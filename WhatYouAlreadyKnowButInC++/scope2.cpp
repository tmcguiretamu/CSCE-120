// This program can't find its variable.
#include <iostream>
using namespace std;

const double PI = 3.14159265;

int main()
{
   int value = 100;
   int value2;

   cout << value << endl; 
   {
	   value2 = 50;
	   
	   int value = 200;
	   
	   cout << value << endl;
	   cout << value2 << endl;
	   
   }
   cout << value << endl;
   cout << PI;


   return 0;
}