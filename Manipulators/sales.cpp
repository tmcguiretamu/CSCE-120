// This program asks for sales amounts for 3 days. The total
// sales are calculated and displayed in a table.
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double day[3], total=0;

	// Get the sales for each day.
	for (int i = 0; i < 3; i++)
	{
		cout << "Enter the sales for day " << (i+1) << ": ";
		cin >> day[i];
		total += day[i];
	}
   
	// Display the sales amounts.
	cout << "\nSales Amounts\n";
	cout << "-------------\n";
	cout << setprecision(2) << fixed;  // sticky
	for (int i = 0; i < 3; i++)
	{
		cout << "Day " << i+1 << ": " << setw(8) << day[i] << endl;	
	}
	cout << "Total: " << setw(8) << total << endl;
	return 0;
} 