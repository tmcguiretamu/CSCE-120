// This program demonstrates random numbers.
#include <iostream>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function
using namespace std;

int main()
{
   // Get the system time.
   unsigned seed = time(0);
   
   // Seed the random number generator.
   srand(seed);
   
   // Display three random numbers.
   cout << "Displaying three random integers" << endl;
   cout << rand() << endl;
   cout << rand() << endl;
   cout << rand() << endl;
   cout << "RAND_MAX on this machine is: " << RAND_MAX << endl;
   return 0;
}