// This program uses a reference variable as a function parameter.
#include <iostream>
using namespace std;

// Function prototype. The parameter is a reference variable.
void doubleTheNum(int &);

int main()
{
   int value;
   cout << "Enter an integer --> ";
   cin >> value ;
   
   cout << "In main, value is " << value << endl;
   cout << "Now calling doubleNum..." << endl;
   doubleTheNum(value);
   cout << "Now back in main. value is " << value << endl;
   return 0;
}

//**********************************************************
// Definition of doubleNum.                                *
// The parameter refVar is a reference variable. The value *
// in refVar is doubled.                                   *
//**********************************************************

void doubleTheNum (int &refVar)
{
   refVar *= 2;
}