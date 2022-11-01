#include <iostream>
using namespace std;

int* separate_even_odd(int* A, unsigned int n)
{
   // allocate output array
   int* out = new int[n];
   
   //step through A, copying all evens into out
   int j = 0;  // track output
   for (int i = 0; i < n; i++)
   {
      if (A[i] % 2 == 0)
      {         
         out[j] = A[i];
         j++;
      }
   }
   
   //step through A again, copying all odds into out
    for (int i = 0; i < n; i++)
   {
      if (A[i] % 2 != 0)
      {         
         out[j] = A[i];
         j++;
      }
   }  
   
   return out;
}

int main()
{
   int A[10] = {9, 8, 4,2, 1, 3, 5, 6, 7, 42};
   int* B = nullptr;
   B = separate_even_odd(A, 10);  
   for (int i = 0; i < 10; i++)
      cout << B[i] << " ";
   cout << endl;
   return 0;
}

  
   