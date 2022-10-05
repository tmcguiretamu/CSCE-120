// see if an input number is a numeric palindrome.
// Can't use string class, but didn't say anything about an array.

#include<iostream>
using namespace std;

bool isPalindrome(int num);

int main()
{
   cout << isPalindrome(12) << endl;
}

bool isPalindrome(int num)
{
   // count digits
   int count = 0;
   int n = num;
   do {
      n /= 10;
      count++;
   } while (n < 0);

   // Create an array to hold the digits      
   int digit[count];
   n = num;
   for (int i = 0; i < count; i++)
   {
      digit[i] = n % 10;
      n /= 10;
   }
   bool pal = true;
   for (int i = 0; i < count/2; i++)
      if (digit[i] != digit[count - i - 1]) 
      {
         pal = false;
         break;
      }
   return pal;   
}