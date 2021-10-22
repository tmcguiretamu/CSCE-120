// This program demonstrates a class with a destructor.
#include <iostream>
#include "ContactInfo.h"
using namespace std;

int main()
{
	// Define a ContactInfo object with the following data:
	// Name: Dr. Tim McGuire  Phone Number: 936-294-1571
	ContactInfo *entry = new ContactInfo("Dr. Tim McGuire", "936-294-1571");

	// Display the object's data.
	cout << "Name: " << entry->getName() << endl;
	cout << "Phone Number: " << entry->getPhoneNumber() << endl;

	return 0;
}