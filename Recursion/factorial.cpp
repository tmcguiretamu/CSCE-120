#include <iostream>

// Function prototype
int factorial (int n);

int main()
{
   unsigned number;

   // Get a number from the user.
   std::cout << "Enter an integer value and I will display its factorial: ";
   std::cin >> number;
   
   // Display the factorial of the number.
   std::cout << "The factorial of " << number << " is ";
   std::cout << factorial(number) << std::endl;
   return 0;
}

// This function calculates the factorial recursively
// Precondition:  n is a non-negative integer
// Postcondition:  the return value is n! (assuming no overflow)
unsigned factorial(unsigned n)
{
   if (n == 0)    // base case
      return 1;
   else           // recursive case
      return n*factorial(n-1);  
}

