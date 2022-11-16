// Specification file for the IntList class
#ifndef INTLIST_H
#define INTLIST_H

class IntList
{
private:
   // Declare a structure for the list
   struct ListNode
   {
      int value;
      struct ListNode *next;
   }; 

   ListNode *head;   // List head pointer

   // Destroy function
   void destroy();

public:
   // Constructor
   IntList()
      { head = nullptr; }

   // Copy constructor
   IntList(const IntList &);

   // Destructor
   ~IntList();

   // List operations
   void appendNode(int);
   void insertNode(int);
   void deleteNode(int);
   void print();
   void reverse();
   int search(int);    // search function
};

#endif