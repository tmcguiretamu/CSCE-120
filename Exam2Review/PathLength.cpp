// pathLength 

#include <iostream>
using std::cout, std::endl;

double pathLength(double** distance, int size, int* path, int length);


int main()
{
   int n=5, m=3;
   double distance[][n] = {   { 0,  30, 10,  70,  10},
                              {30,   0, 45, 100,  50},
                              {10,  45,  0,  85,  20},
                              {70, 100, 85,   0, 100},   
                              {10,  50, 20, 100,   0} };  
   int path[m] = { 0, 1, 2};

   // copy non-dynamic 2D array into a dynamic one.
   double** d = new double*[n];
   for(int i = 0; i < n; i++)
      d[i] = distance[i];
   
   cout << pathLength(d, n, path, m) << endl;
}

double pathLength(double** distance, int n, int* path, int m)
{
   double length = 0.0;
   for(int i = 0; i < m-1; i++)
   {
      length += distance[path[i]][path[i+1]];
   }
   return length;
}
