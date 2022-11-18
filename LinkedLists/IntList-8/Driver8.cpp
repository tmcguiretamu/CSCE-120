//This program uses an Overloaded [] operator
// and an overloaded copy-assignment operator
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

   // Use the [] operators to display the list.
   for (int i = 0; i < myList.getSize(); i++)
	   cout << myList[i] << endl;

   // Use the [] operator to change the value of
   // a node.
   myList[2] = 99;

   // Use the [] operators to display the list.
   cout << "-----------------------------\n";
   for (int i = 0; i < myList.getSize(); i++)
	   cout << myList[i] << endl;

   // copy the list
   IntList otherList;
   
   otherList = myList;
   
   cout << "-----------------------------\n";  
   myList.clear();
   cout << myList.getSize() << " " << otherList.getSize() << endl;
      
   cout << "-----------------------------\n";
   for (int i = 0; i < otherList.getSize(); i++)
	   cout << otherList[i] << endl;
    
   // Now test the exception... 
   try {
      cout << "Testing the exception" << endl;
      cout << otherList[3] << endl;
   }
   catch (const char* e)
   {
      cout << e << "... terminating ... " << endl;
   }

   return 0;
}