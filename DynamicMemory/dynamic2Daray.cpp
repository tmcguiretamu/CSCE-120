#include <iostream>
#include <iomanip>
using namespace std;

void fun(double** x, int n, int m)
{
   x[0][0] = 23.2;
}

int main()
{
   double **sales = new double*[10];  // To dynamically allocate an array (must use *, 
   

   for (int i = 0; i< 10; i++)
   {
      sales[i] = new double[10];
   }
   
   sales[0][0] = 42.3;

   fun(sales, 10, 10);

   cout << sales[0][0];

    return 0;
} 