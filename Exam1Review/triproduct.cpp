// Triproduct numbers
// A positive integer number n is triproduct if it can be obtained by the 
// product of three consecutive positive integers. For example, 120 is 
// triproduct, since 4 * 5 * 6 = 120. 
// Given n > 0, determine if n is triproduct

#include <iostream>
using namespace std;

bool isTriproduct(int);

int main()
{
   int n , max;
   
   cout << "Enter the maximum triproduct number to find, max --> ";
   cin >> max;
   for(n = 1; n <= max; n++)
      if (isTriproduct(n)) 
         cout << n << " is a triproduct number" << endl;
      
   return 0;
}

bool isTriproduct(int n)
{
   // brute force method
   int i = 1;
   while (i * (i+1) * (i+2) < n)
   {
      i++;
   }
   return (i*(i+1)*(i+2) == n);
}