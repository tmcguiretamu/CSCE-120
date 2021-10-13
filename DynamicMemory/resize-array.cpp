// This program demonstrates an array being resized
#include <iostream>  // for cout
#include <cstdlib>   // for rand()
using namespace std;

struct ResizableArray {
   int size;         // number of actual elements in the array
   int capacity;     // the current capacity of the array
   int * data;       // data points to the array containing the data
};

void showValues(ResizableArray); // Function prototype

void append(ResizableArray&, int); 

int main()
{
   ResizableArray a;
   a.size = 0;
   a.capacity = 1;  // deliberately making it small to illustrate resizing
   a.data = new int[a.capacity]; 

   for (int i = 0; i < 24; i++)
      append(a, rand() % 128);  // generate pseudo-random numbers between 0 and 127
   
   
   showValues(a);

   return 0;
}

void showValues(ResizableArray a)
{
   for (int index = 0; index < a.size; index++)
      cout << a.data[index] << " ";
   cout << endl;
}

// append a value to the end of the array
// struct must be passed by reference because we will be changing the array member
void append(ResizableArray& a, int val)
{
   // first of all, if the array is full, resize it
   if(a.size >= a.capacity) {
      // for diagnostic purposes, print out the data
      cout << "Resizing the arrayCurrent capacity = " << a.capacity << "\n";
      showValues(a);
      //make a temp array twice as large
      int *temp = new int[2 * a.capacity];
      // copy the current values into the new array
      for(int index = 0; index < a.size; index++)
         temp[index] = a.data[index];
      // free the original array
      delete [] a.data;
      // make a.data point to the new array and update the capacity
      a.data = temp;
      a.capacity = 2 * a.capacity;
      cout << "New capacity = " << a.capacity << "\n";
   }
   // add the new value.
   a.data[a.size] = val;
   a.size++;    
}
      
   