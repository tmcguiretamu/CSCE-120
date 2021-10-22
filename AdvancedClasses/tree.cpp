// This program demonstrates a static member variable.
#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
   // Define four Tree objects.
   Tree oak;
   Tree pecan;
   Tree pine;
   Tree mesquite;
   
   // Display the number of Tree objects we have.
   cout << "We have " << oak.getObjectCount()
        << " trees in our program!\n";
   return 0;
}