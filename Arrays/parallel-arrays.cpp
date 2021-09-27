// This program uses three parallel arrays: 
// one for employee name, one for hours worked
// and one for pay rate.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
   const int NUM_EMPLOYEES = 5;   // Number of employees
   string name[] = {"Roger Rettig", "Ellen Ebersole", "Logan Lehman", 
						"Dominique Davis", "Casey Carter"};
   int hours[NUM_EMPLOYEES];      // Holds hours worked
   double payRate[NUM_EMPLOYEES]; // Holds pay rates

   // Input the hours worked and the hourly pay rate.
   cout << "Enter the hours worked by " << NUM_EMPLOYEES
        << " employees and their\n"
        << "hourly pay rates.\n";
   for (int index = 0; index < NUM_EMPLOYEES; index++)
   {
      cout << "Hours worked by " << name[index] << ": ";
      cin >> hours[index];
      cout << "Hourly pay rate for " << name[index] << ": ";
      cin >> payRate[index];
   }
   
   // Display each employee's gross pay.
   cout << "Here is the gross pay for each employee:\n";
   cout << fixed << showpoint << setprecision(2);
   for (int index = 0; index < NUM_EMPLOYEES; index++)
   {
      double grossPay = hours[index] * payRate[index];
      cout << setw(18) << name[index] << ": $" << grossPay << endl;
   }
   return 0;
}