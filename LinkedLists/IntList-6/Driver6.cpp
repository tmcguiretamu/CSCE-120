// A Linked List class to hold a series of integers.
// It has member functions for appending, inserting, and deleting nodes
// It also has a destructor to destroy nodes and a copy constructor,
// a reverse() function, and a search function.
// This version adds insert and remove at postion functions

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

   // Insert a node at position 0.
   myList.insert(99, 0);
   cout << "Inserting 99 into myList in position 0:\n";
   myList.print();

   // Insert a node at position 99.
   myList.insert(100, 99);
   cout << "Attemping to Insert a value into myList in position 99:\n";
   myList.print();

   // Insert a node at position 2.
   myList.insert(98, 2);
   cout << "Inserting 98 into myList at position 2:\n";
   myList.print();

   // Remove node at position 0.
   cout << "Removing node 0...\n";
   myList.removeByPos(0);
   myList.print();

   // Try a position that is too big.
   cout << "Trying to Remove node 99...\n";
   myList.removeByPos(99);
   myList.print();

   // Remove node at position 1.
   cout << "Removing node 1...\n";
   myList.removeByPos(1);
   myList.print();
   
   // Remove node at position 2.
   cout << "Removing node 2...\n";
   myList.removeByPos(2);
   myList.print();
   
   // Reverse the list
   cout << "Reversing the list...\n";
   myList.reverse();

   // Display the nodes again
   cout << "Here are the reversed values in myList:\n";
   myList.print();
   cout << endl;
   
   return 0;
}