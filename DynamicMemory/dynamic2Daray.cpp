#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void initialize(double** x, int n, int m)
{
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         x[i][j] = static_cast<double> (rand()) / rand();
}

void print2Darray(double** x, int n, int m)
{

   for (int i = 0; i < n; i++) 
   {
      for (int j = 0; j < m; j++)
         cout << x[i][j] << "\t" ;
      cout << endl;
   }      
}


int main()
{
   const int ROWS = 5; 
   const int COLS = 7;
   double **data = new double*[ROWS];  // To dynamically allocate an array (must use *, 
   
   cout << setw(12) << showpoint << fixed << setprecision(2) << endl;
   cout << "2D array example" << endl;
   for (int i = 0; i< ROWS; i++)
   {
      data[i] = new double[COLS];
   }
   
   initialize(data, ROWS, COLS);

   print2Darray(data, ROWS, COLS);
   
   for (int i = 0; i< ROWS; i++)
      delete [] data[i];
   
   delete [] data;

   return 0;
} 