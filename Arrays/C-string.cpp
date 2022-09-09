// Showing that a C-style string is simply an array of characters
#include <iostream>
using namespace std;

int main()
{

   char str1[] = "howdy";
   char str2[] = {'h' , 'o', 'w', 'd', 'y', '\0'};
   char str3[] = {'h' , 'o', 'w', 'd', 'y'};    // lacks termincation character
   
   cout << str1 << endl; // output: howdy
   cout << str2 << endl; // output: howdy
   cout << str3 << endl; // problematic

}