// This program can't find its variable.
#include <iostream>
using namespace std;

int main()
{


   cout << value << endl;   // ERROR!  value has not yet been declared.

   int value = 100;   


   return 0;
}