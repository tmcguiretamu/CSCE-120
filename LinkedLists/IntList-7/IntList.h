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

   // Declare a member to hold the size of the list
   int size;

   ListNode *head;   // List head pointer

   // Destroy function
   void destroy();

public:
   // Constructor
   IntList()
      { head = nullptr; size = 0; }

   // Copy constructor
   IntList(const IntList &);

   // Destructor
   ~IntList();

   // List operations
   void appendNode(int);
   void insertNode(int);
   void deleteNode(int);
   int getSize();
   void print();
   void reverse();
   void insert(int, int);
   // Overloaded [] operator
   int &operator[](const int &);

};

#endif