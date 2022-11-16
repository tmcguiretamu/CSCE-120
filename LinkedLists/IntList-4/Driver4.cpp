// A Linked List class to hold a series of integers.
// It has member functions for appending, inserting, and deleting nodes
// It also has a destructor to destroy nodes and a copy constructor.
// This version adds a reverse() function.
#include <iostream>
#include "IntList.h"
using std::cout, std::endl;

int main()
{
   // Create an instance of IntList.
   IntList myList;

   // Build a list.
   myList.appendNode(2);  // Append 2 to the list
   myList.appendNode(4);  // Append 4 to the list
   myList.appendNode(6);  // Append 6 to the list

   // Display the nodes.
   cout << "Here are the values in myList:\n";
   myList.print();
   cout << endl;

   // Reverse the list
   cout << "Reversing the list...\n";
   myList.reverse();

   // Display the nodes again
   cout << "Here are the reversed values in myList:\n";
   myList.print();
   cout << endl;

   return 0;
}