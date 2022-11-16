// A basic Linked List class to hold a series of integers.
// It has member functions for appending, inserting, and deleting nodes
// It also has a destructor to destroy nodes.
// It does not yet implement the Rule of Three, however.
#include <iostream>
#include "IntList.h"
using std::cout, std::endl;

int main()
{
   // Create an instance of IntList
   IntList list;

   // Build the list
   list.appendNode(2);  // Append 2 to the list
   list.appendNode(4);  // Append 4 to the list
   list.appendNode(6);  // Append 6 to the list

   // Display the nodes.
   cout << "Here are the initial values:\n";
   list.displayList();
   cout << endl;

   // Insert the value 5 into the list.
   cout << "Now inserting the value 5.\n";
   list.insertNode(5);
   
   // Display the nodes now.
   cout << "Here are the nodes now.\n";
   list.displayList();
   cout << endl;

   // Delete the node holding 6.
   cout << "Now deleting the last node.\n";
   list.deleteNode(6);
   
   // Display the nodes.
   cout << "Here are the nodes left.\n";
   list.displayList();

   return 0;
}