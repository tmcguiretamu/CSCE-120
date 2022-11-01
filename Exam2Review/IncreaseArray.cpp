
/*
Write a function that, given a 2D array and the number of rows and columns to add, resize the array to a size that is the number of previous rows and cols plus the indicated number of rows and columns. First initialize new cells on a row to be the sum of the cell to the left, to the upper left, and the lower left.Next initialize new cells in a column to the sum of the cell above, above and left, and above and right.

void increaseArray(int**& ary, int& numRows, int& numColumns, 
                        int addRows, int addColumns);
*/
#include <iostream>
#include <iomanip>

using namespace std;

void increaseArray(int**& ary, int& numRows, int& numColumns, 
                  int addRows, int addColumns); 

int main()
{
   int nrows = 5, ncolumns = 5, addrows = 2, addcolumns = 3;
   int input[5][5] = {  { 0,  30, 10,  70,  10},
                          {30,   0, 45, 100,  50},
                          { 0,   0,  0,   0,   0},
                          {70, 100, 85,   0, 100},   
                          {10,  50, 20, 100,   0} }; 
                          
   // copy non-dynamic 2D array into a dynamic one.
   int** inArray = new int*[nrows];
   for(int i = 0; i < nrows; i++)
      inArray[i] = input[i];      
   
   increaseArray(inArray, nrows, ncolumns, addrows, addcolumns);

   
   for (int i = 0; i < nrows; i++) {
      for (int j = 0; j < ncolumns; j++) {
         std::cout << std::setw(6) << inArray[i][j];
      }
      std::cout << std::endl;
   }
}

void increaseArray(int**& ary, int& numRows, int& numColumns, 
				int addRows, int addColumns)
{
   // Allocate new array to be size (numRows + addRows) x (numColumns + addColumns)
   int** temp = new int*[numRows + addRows];
   for (int i = 0; i< (numRows + addRows); i++)
      temp[i] = new int[numColumns + addColumns];

   
   // copy ary into temp
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numColumns; j++) {
         temp[i][j] = ary[i][j];
      }
   }
   delete [] ary; 
   ary = nullptr;
   
   // fill new row entries 
   for (int i = 0; i < numRows; i++)
   {
      for (int j = numColumns; j < (numColumns + addColumns); j++) {
         temp[i][j] = temp[i][j-1]; // entry to left
         if (i > 0) 
            temp[i][j] += temp[i-1][j-1]; // entry upper left
          if (i < (numRows + addRows -1) )
            temp[i][j] += temp[i+1][j-1]; // entry lower left        
      }
   }
   
    // fill new column entries 
   for (int i = numRows; i < numRows + addRows; i++)
   {
      for (int j = 0; j < (numColumns + addColumns); j++) {
         temp[i][j] = temp[i-1][j]; // entry above
         if (j> 0) 
            temp[i][j] += temp[i-1][j-1]; // entry above & left
          if (j < (numColumns + addColumns -1) )
            temp[i][j] += temp[i-1][j+1]; // entry above & right        
      }
   }  
      
   numRows += addRows;
   numColumns += addColumns;
   ary = temp;
   
}

