// This program demonstrates the QuickSort Algorithm.
#include <iostream>
using namespace std;

// Function prototypes
// void quickSort(int [], int, int);
int partition(int [], int, int);
void swap(int &, int &);
   const int SIZE = 8;  // Array size
int main()
{

   int count;            // Loop counter
   int array[SIZE] = {83, 52, 24, 65, 17, 35, 96, 42};

   // Display the array contents.
   for (count = 0; count < SIZE; count++)
      cout << array[count] << " ";
   cout << endl;
   
   // Partition the array.
   partition(array, 0, SIZE - 1);
   
   // Display the array contents.
   for (count = 0; count < SIZE; count++)
      cout << array[count] << " ";
   cout << endl;
  
   return 0;
}


//**********************************************************
// partition selects the value in the middle of the        *
// array set as the pivot. The list is rearranged so       *
// all the values less than the pivot are on its left      *
// and all the values greater than pivot are on its right. *
//**********************************************************

int partition(int set[], int start, int end)
{
   int pivotValue, pivotIndex, mid;

   mid = (start + end) / 2;
   swap(set[start], set[mid]);
   cout << "After swapping first with midpoint to get a better "<< 
            "partitioning element" << endl;  
   for (int count = 0; count < SIZE; count++)
      cout << set[count] << " "; 
   cout << endl;   
   cout << "| represents the partitioning point\n";
   cout << "\\ marks the start of unscanned values\n";
   pivotIndex = start;
   pivotValue = set[start];
   for (int scan = start + 1; scan <= end; scan++)
   {
      if (set[scan] < pivotValue)
      {
         pivotIndex++;
         cout << "Swapping " << set[scan] << " with " << set[pivotIndex] << endl;
         swap(set[pivotIndex], set[scan]);
         for (int count = 0; count < SIZE; count++) {
            cout << set[count] << " ";
            if (count == pivotIndex) cout << "| ";
            if (count == scan) cout << "\b\\ ";     
         }
         cout << endl;
      }
   }
   cout << "Swapping " << set[start] << " with " << set[pivotIndex] << endl;
   swap(set[start], set[pivotIndex]);
   return pivotIndex;
}

//**********************************************
// swap simply exchanges the contents of       *
// value1 and value2.                          *
//**********************************************

void swap(int &value1, int &value2)
{
   int temp = value1;

   value1 = value2;
   value2 = temp;
}