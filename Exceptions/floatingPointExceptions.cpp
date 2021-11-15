#include <iostream>
#include <cmath>
using namespace std;

int main() { 
  double a = 0;
  //division by zero
  cout << "a (zero):         " << a << endl;
  a = 7.0/0;
  cout << "a (div by zero):  " << a << endl;
  //negative square root
  a = sqrt(-5.0);
  cout << "a (neg sqr root): " << a << endl;
  a = 0.0/0.0;
  cout << "a (div by zero):  " << a << endl;
 int b = 1/0;
  cout << " b = 1/0" << b << endl;
}
