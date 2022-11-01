/*
Write a function that, given a 2D array, returns a new 2D array containing only the rows that have at least one non-zero element in the row.
int** remove_allzeros_rows(int** matrix, 
					int nrows, 
					int ncolumns, 
					int& new_nrows);
If nrow or ncolumns is zero, throw an exception.
*/
#include <stdexcept>
#include <iomanip>
#include <iostream>

int** remove_allzeros_rows(int** matrix, int nrows, int ncolumns, int& new_nrows);


int main()
{
   int nrows = 5, ncolumns = 5, new_nrows;
   int input[5][5] = {  { 0,  30, 10,  70,  10},
                          {30,   0, 45, 100,  50},
                          { 0,   0,  0,   0,   0},
                          {70, 100, 85,   0, 100},   
                          {10,  50, 20, 100,   0} };   
   // copy non-dynamic 2D array into a dynamic one.
   int** inArray = new int*[nrows];
   for(int i = 0; i < nrows; i++)
      inArray[i] = input[i];      
   
   int** outArray = nullptr;
   outArray = remove_allzeros_rows(inArray, nrows, ncolumns, new_nrows);

   for (int i = 0; i < new_nrows; i++) {
      for (int j = 0; j < ncolumns; j++) {
         std::cout << std::setw(5) << outArray[i][j];
      }
      std::cout << std::endl;
   }
      
}


int** remove_allzeros_rows(int** matrix, int nrows, int ncolumns, int& new_nrows)
{
   // validate input
   if (nrows == 0 || ncolumns == 0) throw std::runtime_error("invalid input");
   
   // initialize variables
   new_nrows =  0;
   
   // Step through matrix counting non-zero rows
   for (int i = 0; i < nrows; ++i)
   {
      bool nonzero = false;
      for (int j = 0; j < ncolumns; ++j)
      {
         if (matrix[i][j] != 0)
         {
            nonzero = true;
            break;
         }
      }
      if (nonzero) new_nrows++;
   }
         
   // Allocate array of int* pointers with size equal to number of new rows.
   int** temp = new int*[new_nrows];
   for (int i = 0; i < new_nrows; i++)
   {
      temp[i] = new int[ncolumns];
   }
   
   int n_out = 0;
 // Step through matrix again, copying non-zero rows to output
    for (int i = 0; i < nrows; ++i)
   {

      bool nonzero = false;
      for (int j = 0; j < ncolumns; ++j)
      {
         if (matrix[i][j] != 0)
         {
            nonzero = true;
            break;
         }
      }
      if (nonzero) 
      {
         for (int j = 0; j < ncolumns; ++j)
            temp[n_out][j] = matrix[i][j];
         n_out++;
      }
   }  
   return temp;
}
