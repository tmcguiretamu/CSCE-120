#include <iostream>
#include <cassert>
#include "my_time.h"
using std::cout, std::endl;
int main() {
   
   assert(isLeapYear(1999) == false);
   assert(isLeapYear(2004) == true);
   assert(isLeapYear(1700) == false);
   assert(isLeapYear(1800) == true);
   assert(isLeapYear(1204) == true);
   
   return 0;
}
