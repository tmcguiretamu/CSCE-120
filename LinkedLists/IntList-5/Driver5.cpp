// A Linked List class to hold a series of integers.
// It has member functions for appending, inserting, and deleting nodes
// It also has a destructor to destroy nodes and a copy constructor,
// and a reverse() function.
// This version adds a search function
// search() returns the position of a specific value in the linked list. 
// The first node in the list is at position 0. 
//If x is not found on the list, the search returns -1.
#include <iostream>
#include "IntList.h"
using std::cout, std::endl;

int main()
{
   // Create an instance of IntList
   IntList list;
   
   // Build the list
   list.appendNode(2);    // Append 2
   list.appendNode(4);    // Append 4
   list.appendNode(6);    // Append 6
   list.appendNode(8);    // Append 8
   list.appendNode(9);    // Append 9

   // Display the list nodes.
   cout << "\nHere are the initial values:\n";
   list.print();
   cout << endl;

   // Search for the value 6.
   cout << "\nSearching for the value 6.";
   cout << "\nFound in node number:  " 
        << list.search(6) << endl << endl;
   
   return 0;
}