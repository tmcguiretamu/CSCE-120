#include <iostream>
using std::cout, std::endl;

struct Node {
  int value;
  Node* next;
  Node(int num = 0) : value{num}, next{nullptr} {}
};

class LinkedList {
//private:
public:  // made public only to allow setup for cycle check
  Node* head;

 public:
   // Constructor
   LinkedList() : head{nullptr} {}
   
   // Destructor
   ~LinkedList();
   
   // copy constructor
   LinkedList(const LinkedList &);
   
   // copy assignment operator
   LinkedList & operator=(const LinkedList &);
   
   // other member functions
   void clear();
   double average() const;
   void removeMax();
   void insertFront(int);
   void reverse();   
   void displayList() const;
   Node* middle() const;
   bool hasCycle() const;
   void appendNode(int num);
};

/*
Linked List Cycle
Write a member function of the class LinkedList that returns 
true if a cycle exists in the linked list, false otherwise.
●	Do not assume the existence of any other functions to use.
●	Return false if the list is empty.
*/
bool LinkedList::hasCycle() const
{
   if (head == nullptr) return false;
   Node *tortise = head;
   Node *hare = head;
   while (tortise != nullptr && hare != nullptr 
            && hare->next !=nullptr) 
   {
      tortise = tortise->next;
      hare = hare->next->next;
      if (tortise == hare) return true;
   }
   return false;
}


/*
Middle of the List
Write a member function of the class LinkedList that returns 
a pointer to the element in the middle of the list (if the 
list has n elements, it should return a pointer to the 
([n/2]+1)-th element).
	Do not assume the existence of any other functions to use.
	Return nullptr if the list is empty.
*/
Node* LinkedList::middle() const
{
   // count number of nodes in list
   unsigned n = 0;
   Node* p = head; 
   if (p == nullptr) return nullptr;
   while (p != nullptr) {
      p = p->next;
      ++n;
   }
   n = n/2;
   p = head;
   for (unsigned i=0; i < n; ++i)
      p = p->next;
   return p;

}

/* 
LinkedList Average
Write a member function of the class LinkedList (a simply-linked list, with a pointer head to its first element) that returns the average of the elements in the list. 
   Do not assume the existence of any other functions to use.
   Throw an exception if the list is empty.
*/
double LinkedList::average() const
{
   double sum = 0.0; 
   unsigned count = 0;
   Node* p = head; 
   if (p == nullptr) throw " list empty\n";
   while (p != nullptr) {
      sum += p->value;
      p = p->next;
      ++count;
   }
   return sum/count;
}

void LinkedList::insertFront(int num) 
{
   Node *newNode = nullptr;

   // Allocate a new node & store num
   newNode = new Node;
   newNode->value = num;
   newNode->next = head;
   head = newNode;
}

/*
Remove all Maximum
Write a member function of the class LinkedList that removes from the list all occurrences of the maximum element in the list. 
●	Observe that the list can be and can become empty.
●	Do not assume the existence of any other functions to use.

*/
void LinkedList::removeMax()
{
   if (head == nullptr) return;  // nothing to do
   
   // traverse the list to find the maximum value
   int max = head->value;
   Node* nodePtr = head->next;
   while (nodePtr != nullptr) {
      if (nodePtr->value > max) max = nodePtr->value;
      nodePtr = nodePtr->next;
   }

   // traverse the list again, removing all max values
   // Determine if the first node is a max.
   while (head != nullptr && head->value == max) {
      nodePtr = head->next;
      delete head;
      head = nodePtr;
   }
   
   // to head of list
   if (head == nullptr) return;
   Node *previousNode = head, *temp = nullptr;
   nodePtr = head->next;
   // Skip all nodes whose value member is 
   // not equal to max.
   while (nodePtr != nullptr ) {  
      if (nodePtr->value == max) {
         temp = nodePtr;
         previousNode->next = nodePtr->next;
         nodePtr = nodePtr->next;
         delete temp; 
         temp = nullptr;
      }
      else {
         previousNode = nodePtr;
         nodePtr = nodePtr->next;
      }
   }
}


void LinkedList::clear() 
{
	Node *nodePtr, *nextNode = nullptr;

   nodePtr = head;
   while (nodePtr != nullptr) {
      nextNode = nodePtr->next;
      delete nodePtr;
      nodePtr = nextNode;
   }

   head = nullptr;
}

LinkedList::~LinkedList() 
{
   cout << "Calling Destructor" << endl;
   clear();
}

//**************************************************
// Copy constructor                                *
//**************************************************
LinkedList::LinkedList(const LinkedList &other)
{
	Node *nodePtr = nullptr;

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
}

//**************************************************
// appendNode appends a node containing the        *
// value pased into num, to the end of the list.   *
//**************************************************

void LinkedList::appendNode(int num)
{
	Node *newNode, *nodePtr = nullptr;

   // Allocate a new node & store num
   newNode = new Node;
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
}

//**************************************************
// Copy assignment operator                        *
//**************************************************

LinkedList &LinkedList::operator=(const LinkedList &other){
	
	if(this != &other){ // prevent self-copy


		if(other.head == nullptr) {
         head = nullptr;
      }
		else {
         clear();
         Node *nodePtr = nullptr;

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
		}
	}
	return *this; 
}


void LinkedList::reverse()
{     
	Node  *newHead = nullptr,
         *newNode = nullptr,
         *nodePtr = nullptr,
         *tempPtr = nullptr;

   // Traverse the list, building a
   // copy of it in reverse order.
   nodePtr = head;
   while (nodePtr) {
      // Allocate a new node & store the 
	   // value of the current list node in it.
      newNode = new Node;
      newNode->value = nodePtr->value;
      newNode->next = nullptr;
	  
      // Shift the existing nodes in the new
      // list down one, inserting the new
      // node at the front.
      if (newHead != nullptr) {
         tempPtr = newHead;
         newHead = newNode;
         newHead->next = tempPtr;
      }
      else {
		  newHead = newNode;
      }

	  // Go to the next node in the list.
	  nodePtr = nodePtr->next;
   }

   // Destroy the existing list.
   clear();

   // Make head point to the new list.
   head = newHead;
}

void LinkedList::displayList() const
{
   Node *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr points to a node, traverse
   // the list.
   while (nodePtr) {
      // Display the value in this node.
      cout << nodePtr->value << endl;

      // Move to the next node.
      nodePtr = nodePtr->next;
   }
}    


  
int main()
{

   LinkedList myList;
   
   myList.insertFront(6);
   myList.insertFront(1);
   myList.insertFront(2);
   myList.insertFront(6);
   myList.insertFront(3);
   myList.insertFront(0);   
   myList.insertFront(6);
   myList.insertFront(5);
   myList.insertFront(4);
   myList.insertFront(6);
  
   cout << "Here is the list:" << endl;
   myList.displayList();

   cout << "Here is the list after reversing:" << endl;
   myList.reverse();
   myList.displayList();
   
   try {
      cout << "Average value: " << myList.average() << endl;
   }
   catch (char const * msg) {
      cout << msg << endl;
   }
   
   myList.removeMax();
   myList.displayList();
   
   cout << "middle value: " << (myList.middle())->value << endl;
   
   if (myList.hasCycle()) 
      cout << "List has a cycle" << endl;
   else
      cout << "List has no cycle" << endl;
   
   // head ptr made public so we can do this
   (myList.middle())->next = myList.head;  
   if (myList.hasCycle()) {
      cout << "List has a cycle" << endl;
      exit(-1);
   }
   else
      cout << "List has no cycle" << endl;   
}
      
     