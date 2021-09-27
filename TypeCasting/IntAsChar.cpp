// This program uses a type cast expression to print a character
// from a number.
#include <iostream>
using namespace std;

int main()
{
   int number;
   
   // Display ASCII codes for printing characters
   for (number = 32; number < 127; number++)
   {
      // Display the value of the number variable.
      cout << number << "\t";
   
      // Display the value of number converted to the char data type.
      cout << static_cast<char>(number) << "\t";
      if (number % 5 == 0) 
         cout << endl;
   }
   cout << endl;
   return 0;
}