#include <iostream>
#include <stdexcept>
using std::cin, std::cout, std::endl;

double divide(double left, double right)
{
   if ( right == 0)
   {
      throw std::runtime_error("Error: Cannot divide by zero.");
   }
   return left / right;
}

int main()
{
   double x = 0;
   double y = 0;
   cout << "Enter two numbers: ";
   cin >> x >> y;

   try 
   {
      double result = divide(x, y);
      cout << result << endl;
   }      
   catch (std::runtime_error& e)
   {
      cout << e.what() << endl;
   }
   return 0;
}
