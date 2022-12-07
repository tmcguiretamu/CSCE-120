// see if an input number is a numeric palindrome.


#include<iostream>
using namespace std;

bool isPalindrome(long);

int main()
{
   long num;
   cout << "Enter an integer (max 19 digits) -> ";
   cin >> num;
   if (isPalindrome(num))
      cout << num << " is a palendrome." << endl;
   else
      cout << num << " is not a palindrome." << endl;
}

bool isPalindrome(long num)
{
   int num_digits = 0;
   int multiplier = 1;
   long newValue = 0;
   
   // compute last digit
   int last_digit = num % 10;
   
   // a single digit is a palindrome
   if (last_digit == num)
      return true;
   
   // compute first digit
   long first_digit = num;
   do {
      first_digit /= 10;
      ++num_digits;
      multiplier *= 10;
   } while (first_digit > 9);
   
   // if first and last digits are equal it's a palindrome
   if (first_digit == last_digit) {
      newValue = (num - first_digit*multiplier - last_digit)/10;
      return isPalindrome( newValue );
   }
   return false;
      
}