// This program demonstrates a 2D array being resized
#include <iostream>  // for cout

using namespace std;

// print a 2D array
void printArray(int **, int rows, int cols);

// append rows of second 2D array to first
void appendArray(int **first, int rows, int fCols, int ** second, int sCols); 

int main()
{
   const int ROWS = 5;
   const int F_COLS = 5;
   const int S_COLS = 4;
  
   
   // create two 2D dynamic arrays
   cout << "creating first\n";
   int ** first = new int*[ROWS];
   for (int i=0; i < ROWS; ++i)
      first[i] = new int[F_COLS];
   cout << "creating second\n";
   int ** second = new int*[ROWS];
   for (int i=0; i < ROWS; ++i)
      second[i] = new int[S_COLS]; 
   
   // fill the arrays 
   cout << "filling first\n";   
   for(int i = 0; i < ROWS; ++i) 
      for (int j = 0; j < F_COLS; ++j)
         first[i][j] = i+j;
      
   cout << "filling second\n";    
   for(int i = 0; i < ROWS; ++i) 
      for (int j = 0; j < S_COLS; ++j)
         second[i][j] = i+j;      
   
   // print the arrays
   cout << "first array:\n";
   printArray(first, ROWS, F_COLS);
   cout << "\nsecond array:\n";
   printArray(second, ROWS, S_COLS);
   
   // append the second array to the first
   appendArray(first, ROWS, F_COLS, second, S_COLS);
   
   cout << "\nNow first array has the following contents:\n";
   printArray(first, ROWS, F_COLS+S_COLS);
   
   // delete the array
   for(int i = 0; i < ROWS; ++i)
   {   
      delete [] first[i];
      first[i] = nullptr;
   }
   delete [] first;
   first = nullptr;
   
   return 0;
}
   
// print a 2D array
void printArray(int ** a, int rows, int cols)
{
   for(int i = 0; i < rows; ++i) 
   {
      for (int j = 0; j < cols; ++j)
         cout << a[i][j] << " ";
      cout << "\n";
   }
}

// append rows of second 2D array to first
void appendArray(int **first, int rows, int fCols, int ** second, int sCols)
{
   for (int i = 0; i < rows; ++i)
   {
      int *temp = new int[fCols + sCols];
      for(int j = 0; j < fCols; ++j)
         temp[j] = first[i][j];
      for (int j = 0; j < sCols; ++j)
         temp[fCols + j] = second[i][j];
      delete [] first[i];
      first[i] = temp;
      delete [] second[i];
      second[i] = nullptr;
   }
   delete [] second;
   second = nullptr;
}   
   
  
  