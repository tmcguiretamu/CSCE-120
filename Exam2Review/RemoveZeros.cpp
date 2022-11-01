/*
Write a function that, given a 2D array, returns a new 2D array containing only the rows that have at least one non-zero element in the row.
int** remove_allzeros_rows(int** matrix, 
					int nrows, 
					int ncolumns, 
					int& new_nrows);
If nrow or ncolumns is zero, throw an exception.
*/

int** remove_allzeros_rows(int** matrix, int nrows, int ncolumns, int& new_nrows)
{
   // validate input
   if (nrows == 0 || ncolumns == 0) throw runtime_error();
   
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
   int** temp = new int*[new_nrows]
   for (int i = 0; i < new_nrows; i++)
   {
      temp[i] = new int[ncolumns];
   }
   
   // Step through matrix again, copying non-zero rows to output
    for (int i = 0; i < nrows; ++i)
   {
      int n_out = 0;
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