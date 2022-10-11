#include <iostream>
using namespace std;

int main()
{
   int x = 42;
   int *intptr;
   intptr = &x;
   cout << *intptr << endl;
   return 0;
}
 