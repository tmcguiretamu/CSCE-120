// This program displays three rows of numbers.
#include <iostream>
#include <iomanip>      // Required for setw
using namespace std;

int main()
{
   int num[] = { 1234,    5,   678,
					90,    1, 2345,
				   678, 9101,   12};
   
   // Note that setw is NOT sticky 
   // Display the first row of numbers
   cout << setw(6) << num[0] << setw(6) 
        << num[1] << setw(6) << num[2] << endl;

   // Display the second row of numbers
   cout << setw(6) << num[3] << setw(6) 
        << num[4] << setw(6) << num[5] << endl;

   // Display the third row of numbers
   cout << setw(6) << num[6] << setw(6) 
        << num[7] << setw(6) << num[8] << endl;
   return 0;
}