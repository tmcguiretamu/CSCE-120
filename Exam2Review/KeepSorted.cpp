// This program demonstrates an array being resized
#include <iostream>  // for cout
#include <cstdlib>   // for rand()
using namespace std;

struct SortedArray {
   int size;         // number of actual elements in the array
   int capacity;     // the current capacity of the array
   int * data;       // data points to the array containing the data
};

void showValues(SortedArray); // Function prototype

void insert(SortedArray&, int); 

int main()
{
   SortedArray a;
   a.size = 0;
   a.capacity = 10;  
   a.data = new int[a.capacity]; 

   for (int i = 0; i < 24; i++)
      insert(a, rand() % 128);  // generate pseudo-random numbers between 0 and 127


   showValues(a);

   return 0;
}

void showValues(SortedArray a)
{
   for (int index = 0; index < a.size; index++)
      cout << a.data[index] << " ";
   cout << endl;
}

// insert a value into its proper 
// struct must be passed by reference because we will be changing the array member
void insert(SortedArray& a, int val)
{
   // first of all, if the array is full, resize it
   if(a.size >= a.capacity) {
      // for diagnostic purposes, print out the data
      cout << "Resizing the array Current capacity = " << a.capacity << "\n";
      showValues(a);
      cout << "Need to add " << val << endl;
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
   // insert the new value.
   int i = a.size;
   while (i > 0 && a.data[i-1] > val) {
      a.data[i] = a.data[i-1];
      i--;
   }
   a.data[i] = val;
   a.size++;    
}
      
   