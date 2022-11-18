// Implementation file for the IntList class
#include <iostream>
#include "IntList.h"
using std::cout, std::endl;

//**************************************************
// Copy assignment operator                        *
//**************************************************

IntList &IntList::operator=(const IntList &other){
	
	if(this != &other){ // prevent self-copy

		size = other.size;

		if(other.size == 0) {
         head = nullptr;
      }
		else {
         destroy();
         ListNode *nodePtr = nullptr;

         // Initialize the head pointer.
         head = nullptr;

         // Point to the other object's head.
         nodePtr = other.head;
         
         // Traverse the other object.
         while (nodePtr)
         {
            // Append a copy of the other object's
            // node to this list.
            appendNode(nodePtr->value);

            // Go to the next node in the other object.
            nodePtr = nodePtr->next;
         }
         size = other.size;
		}
	}
	return *this; 
}


//**************************************************
// Copy constructor                                *
//**************************************************
IntList::IntList(const IntList &other)
{
	ListNode *nodePtr = nullptr;

   // Initialize the head pointer.
	head = nullptr;

   // Point to the other object's head.
   nodePtr = other.head;

   // Traverse the other object.
   while (nodePtr)
   {
      // Append a copy of the other object's
      // node to this list.
      appendNode(nodePtr->value);

	  // Go to the next node in the other object.
      nodePtr = nodePtr->next;
   }
   size = other.size;
}

//**************************************************
// appendNode appends a node containing the        *
// value pased into num, to the end of the list.   *
//**************************************************

void IntList::appendNode(int num)
{
	ListNode *newNode, *nodePtr = nullptr;

   // Allocate a new node & store num
   newNode = new ListNode;
   newNode->value = num;
   newNode->next = nullptr;

   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
      head = newNode;
   else  // Otherwise, insert newNode at end
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Find the last node in the list
      while (nodePtr->next)
         nodePtr = nodePtr->next;

      // Insert newNode as the last node
      nodePtr->next = newNode;
   }

   // Update the size.
   size++;
}

//**************************************************
// The print function displays the value           *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************

void IntList::print()
{
	ListNode *nodePtr = nullptr;

   nodePtr = head;
   while (nodePtr)
   {
      cout << nodePtr->value << endl;
      nodePtr = nodePtr->next;
   }
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************

void IntList::insertNode(int num)
{
	ListNode *newNode, *nodePtr, *previousNode = nullptr;

   // Allocate a new node & store num
   newNode = new ListNode;
   newNode->value = num;
   
   // If there are no nodes in the list
   // make newNode the first node
   if (!head)
   {
      head = newNode;
	  newNode->next = nullptr;
   }
   else  // Otherwise, insert newNode
   {
      // Initialize nodePtr to head of list and
      // previousNode to a null pointer.
      nodePtr = head;
	  previousNode = nullptr;

      // Skip all nodes whose value member is less
      // than num.
	  while (nodePtr != nullptr && nodePtr->value < num)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If the new node is to be the 1st in the list,
      // insert it before all other nodes.
	  if (previousNode == nullptr)
      {
         head = newNode;
         newNode->next = nodePtr;
      }
      else  // Otherwise, insert it after the prev node
      {
         previousNode->next = newNode;
         newNode->next = nodePtr;
      }
   }

   // Update the size.
   size++;
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************

void IntList::deleteNode(int num)
{
	ListNode *nodePtr, *previousNode = nullptr;

   // If the list is empty, do nothing.
   if (!head)
      return;
   
   // Determine if the first node is the one.
   if (head->value == num)
   {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   else
   {
      // Initialize nodePtr to head of list
      nodePtr = head;

      // Skip all nodes whose value member is 
      // not equal to num.
	  while (nodePtr != nullptr && nodePtr->value != num)
      {  
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }

      // If nodePtr is not at the end of the list, 
      // link the previous node to the node after
      // nodePtr, then delete nodePtr.
      if (nodePtr)
      {
         previousNode->next = nodePtr->next;
         delete nodePtr;
      }
   }

   // Update the size.
   size--;
}

//**************************************************
// The getSize function returns the size of the    *
// list.                                           *
//**************************************************
int IntList::getSize()
{
	return size;
}

void IntList::reverse()
{
	ListNode *newHead = nullptr,
		     *newNode,
			 *nodePtr,
			 *tempPtr;

   // Traverse the list, building a
   // copy of it in reverse order.
   nodePtr = head;
   while (nodePtr)
   {
      // Allocate a new node & store the 
	  // value of the current list node in it.
      newNode = new ListNode;
      newNode->value = nodePtr->value;
	  newNode->next = nullptr;
	  
	  // Shift the existing nodes in the new
	  // list down one, inserting the new
	  // node at the top.
	  if (newHead != nullptr)
	  {
		  tempPtr = newHead;
		  newHead = newNode;
		  newNode->next = tempPtr;
	  }
	  else
	  {
		  newHead = newNode;
	  }

	  // Go to the next node in the list.
	  nodePtr = nodePtr->next;
   }

   // Destroy the existing list.
   destroy();

   // Make head point to the new list.
   head = newHead;
}

//**************************************************
// The clear function resets the list to empty     *
//**************************************************

void IntList::clear()
{
   destroy();
}

//**************************************************
// The destroy helper function destroys all the    *
// nodes in the list.                              *
//**************************************************

void IntList::destroy()
{
	ListNode *nodePtr, *nextNode = nullptr;

   nodePtr = head;
   while (nodePtr != nullptr)
   {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }

   head = nullptr;
   size = 0;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************

IntList::~IntList()
{
	destroy();
}

//*********************************************
//  IntList::insert                        *
//  Insert item at given position             *
//*********************************************
void IntList::insert(int value, int pos)
{
    // Allocate a new node & store the 
    // value of the current list node in it.
    ListNode *newNode = new ListNode;
    newNode->value = value;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		size++;
		return;
	}
    
	if (pos == 0) 
    {
		newNode->next = head;
		head = newNode;
		size++;
      return;
    }

    ListNode *p = head;  // Walk through nodes
    int numberToSkip = 1;
    while (numberToSkip <= pos)
    {
		if (p->next == nullptr || numberToSkip == pos)
       {
	      ListNode *tempPtr = p->next;
		  p->next = newNode; 
		  newNode->next = tempPtr;
		  size++;
        return;
       }
       // Not at end and have not skipped enough
       // So skip another one
       p = p->next;
       numberToSkip++;
    }
}


//*********************************************
//  IntList::operator[]                    *
//  Overloads the [] operator                *
//*********************************************
int &IntList::operator[](const int &sub)
{
   ListNode *p = head;  // To walk through the nodes
   int pos = 0;

   if (sub >= size)
   {
	   throw "Invalid subscript\n";
   }

   while (p->next != nullptr && sub > pos)
   {
	   p = p->next;
	   pos++;
   }

   return p->value;
}