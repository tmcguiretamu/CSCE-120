// sample main program showing multiple file compilation
// helper.h has function prototypes
// helper.cpp has function definitions
// Usage:  g++ -std=c++17 main.cpp helper.cpp

#include <iostream>
#include "helper.h"
using std::cout, std::endl;

int main() 
{
cout << std::boolalpha;
cout << "2 < 5? " << lessThan(2, 5) << endl;
cout << "2 == 5? " << equalTo(2, 5) << endl;
cout << "5 < 5? " << lessThan(5, 5) << endl;
cout << "5 == 5? " << equalTo(5, 5) << endl;
cout << "7 < 5? " << lessThan(7, 5) << endl;
cout << "7 == 5? " << equalTo(7, 5) << endl;
return 0;
}
