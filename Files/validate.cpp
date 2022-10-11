// This program demonstrates input validation 
#include <iostream>
#include <limits>

using namespace std;


int main()
{
	cout << "Enter an integer: ";
	int val;
	cin >> val;

	while(!cin.good()) { // any of the stream state bits is set
		cout << "Input status:" << endl;
		cout << " fail bit: " << cin.fail() << endl;
		cout << " bad bit: " << cin.bad() << endl;
		cout << " good bit: " << cin.good() << endl;
		cin.clear(); // set all stream state bits to zero, buffer NOT cleared
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// clear the buffer of everything, i.e. make clean slate for input  

		cout << "Enter a valid integer: ";
		cin >> val;
	}

	cout << "You entered: " << val << endl;

	return 0;
}

