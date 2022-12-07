// C++ program to reverse a string using recursion
#include <string>
#include <iostream>
using std::cout, std::endl, std::string; 
 
/* Function to print reverse of the passed string */
void reversePrint(string str)
{
   size_t len = str.length();
   if(len > 0 )
   {
      cout << str.at(len-1);
      reversePrint(str.substr(0,len-1));
   }
}
 
/* Driver program to test above function */
int main()
{
    string a = "Able was I ere I saw Elba";
    cout << a << endl;
    reversePrint(a);
    cout << endl;
    return 0;
}