// C++ program to reverse a string using recursion
#include <string>
#include <iostream>
using namespace std;
 
/* Function to print reverse of the passed string */
void reversePrint(string str)
{
   if(str.length() > 0 )
   {
      reversePrint(str.substr(1));
      cout << str.at(0);
   }
}
 
/* Driver program to test above function */
int main()
{
    string a = "Able was I ere I saw Elba";
    cout << a << endl;
 //   cout << a.substr(0,a.length() - 1);
    reversePrint(a);
    cout << endl;
    return 0;
}