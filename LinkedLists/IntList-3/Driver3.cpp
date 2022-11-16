// A basic Linked List class to hold a series of integers.
// It has member functions for appending, inserting, and deleting nodes
// It also has a destructor to destroy nodes.
// This version adds a copy constructor
#include <iostream>
#include "IntList.h"
using std::cout, std::endl;

int main()
{
   // Create an instance of IntList.
   IntList firstList;

   // Build a list.
   firstList.appendNode(2);  // Append 2 to the list
   firstList.appendNode(4);  // Append 4 to the list
   firstList.appendNode(6);  // Append 6 to the list

   // Display the nodes.
   cout << "Here are the values in firstList:\n";
   firstList.print();
   cout << endl;

   // Make a copy of firstList.
   IntList secondList(firstList);

   // Display the nodes in secondList
   cout << "Here are the values in secondList.\n";
   secondList.print();
   cout << endl;

   return 0;
}