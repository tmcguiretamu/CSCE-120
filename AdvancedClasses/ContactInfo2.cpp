// This program demonstrates a class with a destructor.
#include <iostream>
#include <string>
#include "ContactInfo2.h"
using namespace std;

int main()
{
	// Define a ContactInfo object with the following data:
	// Name: Dr. Tim McGuire  Phone Number: 936-294-1571
	ContactInfo2 *entry = new ContactInfo2("Dr. Tim McGuire", "936-294-1571");

	// Display the object's data.
	cout << "Name: " << entry->getName() << endl;
	cout << "Phone Number: " << entry->getPhoneNumber() << endl;

	return 0;
}