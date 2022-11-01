#include <iostream>
using namespace std;

int* get_even_numbers(int* A, unsigned int n, unsigned int& m);

int main()
{
   unsigned int m;
   int A[] = {1, 2, 3, 4, 5, 5, 42, 19, 33, 66};
   int* out = nullptr;
   out = get_even_numbers(A, 10, m);
   for (int i = 0; i < m; ++i)
      cout << out[i] << " ";
   cout << endl;
   return 0;

}


int* get_even_numbers(int* A, unsigned int n, unsigned int& m)
{
   // first count all even numbers in A
   int count = 0;
   for (int i = 0; i < n; i++)
   {
      if (A[i] % 2 == 0) count++;
   }
      
   // second, create array of appropriate size
   int *temp = new int[count];
   
   // third, copy even values into it
   int j = 0;
   for (int i = 0; i < n; i++)
   {
      if (A[i] % 2 == 0)
      {
         temp[j] = A[i];
         j++;
      }
   }
   m = count;
   return temp;
}