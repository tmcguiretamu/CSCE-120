#include <iostream>

// Function prototype
unsigned long factorial (unsigned n);

int main()
{
   unsigned number;

   // Get a number from the user.
   std::cout << "Enter an integer value and I will display its factorial: ";
   std::cin >> number;
   for (unsigned n = 0; n <= number; n++) {
      // Display the factorial of the number.
      std::cout << "The factorial of " << n << " is ";
      try {
         unsigned long result = factorial(n);
         std::cout << result << std::endl;
      }
      catch (char const * e) {
         std::cout << e;
      }
   }
   return 0;
}

// This function calculates the factorial recursively
// Precondition:  n is a non-negative integer
// Postcondition:  the return value is n! (assuming no overflow)
unsigned long factorial(unsigned n)
{
   if (n > 20) throw "result exceeds 2^64\n";
   if (n == 0)    // base case
      return 1;
   else           // recursive case
      return n*factorial(n-1);  
}

