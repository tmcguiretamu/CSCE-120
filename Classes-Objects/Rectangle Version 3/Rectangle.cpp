// Implementation file for the Rectangle class.
// This version has a constructor.
#include "Rectangle.h"   // Needed for the Rectangle class
#include <iostream>      // Needed for cout, cerr, etc
#include <cstdlib>       // Needed for the exit function
using namespace std;

//***********************************************************
// The constructor initializes width and length to 0.0.     *
//***********************************************************

Rectangle::Rectangle()
{
   cout << "In the constructor" << endl;	
   width = 1.0;
   length = 1.0;
}

//***********************************************************
// setWidth sets the value of the member variable width.    *
//***********************************************************

void Rectangle::setWidth(double w)
{
   if (w >= 0)
      width = w;
   else
   {
      cerr << "Invalid width\n";
      exit(EXIT_FAILURE);
   }
}

//***********************************************************
// setLength sets the value of the member variable length.  *
//***********************************************************

void Rectangle::setLength(double len)
{
   if (len >= 0)
      length = len;
   else
   {
      cerr << "Invalid length\n";
      exit(EXIT_FAILURE);
   }
}