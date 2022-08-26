// This program demonstrates boolean variables.
#include <iostream>
using namespace std;

int main()
{
   bool bool1, bool2;

   bool1 = true;
   cout << bool1 << endl;
   bool2 = false;
   cout << bool2 << endl;
   
   cout << !bool2 << endl;          // NOT operator
   cout << (bool1 && bool2) << endl;  // AND operator
   cout << (bool1 || bool2) << endl;  // OR operator
   
   return 0;
} 