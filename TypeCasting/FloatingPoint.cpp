// This program shows floating-point is not exact.
#include <iostream>
using std::cout, std::endl;

int main()
{
   const int TIMES = 100000;
   const float X = 0.1f;  // the f suffix forces a float constant
   float sum = 0.0f;      // double is default for fp literals 
   
   // sum 0.1 TIMES times
   for(int i=0; i<TIMES; ++i)
      sum += X;
   
   cout << "Summing 0.1 " << TIMES << " times yields:" << sum << endl;
   
   return 0;
} 