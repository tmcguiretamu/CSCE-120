// This program will print a table of Fibonacci numbers
#include <iostream>  // for cout, circle
#include <iomanip>   // for setw

static unsigned numCalls = 0;
// Function prototype
unsigned fib (const unsigned n);

int main()
{
   unsigned max;

   // Get a number from the user.
   std::cout << "Enter the number of Fibonacci numbers in the table: ";
   std::cin >> max;
 
   // Display the table of Fibonacci numbers.
   std::cout << "   n           fib(n)              number of fcn calls\n";
   std::cout << "------------------------------------------------------\n";
   for (unsigned i = 0; i <= max; i++) {
      numCalls = 0;
      std::cout << std::setw(5) << i << std::setw(15) << fib(i) << std::setw(15) << numCalls << "\n";
   }
   return 0;
}

// This function calculates the factorial recursively
// Precondition:  n is a non-negative integer
// Postcondition:  the return value is n! (assuming no overflow)
unsigned fib(const unsigned n) {  
    ++numCalls;
    if (n <= 1) {
        return n;
    } 
    else {
        return fib(n-1) + fib(n-2);
    }
}

