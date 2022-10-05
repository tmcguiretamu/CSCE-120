// Multiples
// Given positive integers n, k and l, print the first n positive 
// integer numbers that are multiple of k, l or both. 
// Example: n = 6, k = 2 and l = 3, you should print:
//     2 3 4 6 8 9

#include <iostream>
using namespace std;

int main()
{
   int n, k, l;
   
	cout << "Given positive integers n, k and l, print the first n \n positive integer numbers that are multiple of k, l or both.\n";
   cin >> n >> k >> l ;
   
	int count = 0;   // number of multiples so far
   int num = 1;      // num is starting point
   while (count < n)
   {
      if ( (num % k) == 0 || (num % l) == 0) 
      {
         cout << num << " ";
         count++;
      }
      num++;
   }
   cout << endl;
	return 0;
}