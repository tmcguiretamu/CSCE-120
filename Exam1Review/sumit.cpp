#include <iostream>
using namespace std;

/*
	Write a program that given:
		n such as 0 < n < 5000
		a list of n numbers in increasing order
		a target number k
	prints two distinct elements from the list such that their sum is equal to the target k
	if such a pair exists and ”none” otherwise.
*/
int main ()
{
   const int SIZE = 9;
   int a[] = {1, 2, 3, 5, 7, 9, 11, 15, 17};
   
   int target;
   cout << "Enter a target value:  ";
   cin >> target;
   
   bool found = false;
   for (int i = 0; i < SIZE; i++)
      for (int j = i+1; j < SIZE; j++)
      {
         if (a[i] + a[j] == target) {
            found = true;
            cout << a[i] << " " << a[j] << "\n";
         }
      }
   if (!found)
      cout << "None found\n";
   
   return 0;
}