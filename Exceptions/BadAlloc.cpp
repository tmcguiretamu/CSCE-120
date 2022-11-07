// bad_alloc example
// compile without -fsanitize=undefined,address (/usr/bin/g++)
#include <iostream>     // std::cout
#include <new>          // std::bad_alloc


int main () {
  int* myarray ;
  try
  {
    myarray= new int[10000000000];
    std::cout << "Allocation successful\n";
  }
  catch (std::bad_alloc& ba)
  {
    std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    exit(1);
  }
  delete [] myarray;
  return 0;
}