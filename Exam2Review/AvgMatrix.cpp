// avgMatrix 

#include <iostream>
using std::cout, std::endl;

void avgMatrix(double** inArray, int rows, int columns, double** outArray);

int main()
{
   int n=5, m=5;
   cout << "Initializing Array" << endl;
   double inArray[5][5] = {   { 0,  30, 10,  70,  10},
                              {30,   0, 45, 100,  50},
                              {10,  45,  0,  85,  20},
                              {70, 100, 85,   0, 100},   
                              {10,  50, 20, 100,   0} };  
   for(int i = 0; i < n; i++) 
   {
      for (int j = 0; j < m; j++)
         cout << inArray[i][j] << " ";
      cout << endl;
   }
   cout << "allocating next array \n";
   double** d = new double*[n];
   cout << "allocating rows \n";  
   for(int i = 0; i < m; i++)
      d[i] = inArray[i];
   cout << "allocating output array\n";
   double** out = new double*[n];
   cout << "allocating rows \n";  
   for(int j = 0; j < m; j++)
      out[j] = new double[m]; 
   cout << "rows allocated\n";   
   avgMatrix(d, n, m, out);
   cout << "result is" << endl;
   for(int i = 0; i < n; i++) 
   {
      for (int j = 0; j < m; j++)
         cout << out[i][j] << " ";
      cout << endl;
      delete [] out[i];
      out[i] = nullptr;
   }
   delete [] out;
   out = nullptr;
   delete [] d;
   
}


void avgMatrix(double** inArray, int rows, int columns, double** outArray)
{
   for(int i = 0; i < rows; i++)
   {
      for( int j = 0; j < columns; j++)
      {
         double sum = 0; int count = 0;
         if (i > 0 && j > 0)        
            { sum += inArray[i-1][j-1]; ++count; }
         if (i > 0)                 
            { sum += inArray[i-1][j]; ++count; }
         if (i > 0 && j < columns-1)  
            { sum += inArray[i-1][j+1]; ++count; }
         if (j > 0)                 
            { sum += inArray[i][j-1]; ++count; }
         if (j < columns-1)               
            { sum += inArray[i][j+1]; ++count; }
         if (i < rows-1 && j > 0)                           
            { sum += inArray[i+1][j-1]; ++count; }
         if (i < rows-1)               
            { sum += inArray[i+1][j]; ++count; }
         if (i < rows-1 && j <columns-1)               
            { sum += inArray[i+1][j+1]; ++count; }
         outArray[i][j] = sum / count;
      }
   }
}