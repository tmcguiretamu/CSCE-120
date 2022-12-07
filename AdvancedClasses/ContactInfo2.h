// Specification file for the Contact class.
#ifndef CONTACTINFO2_H
#define CONTACTINFO2_H
#include <string>   
#include <iostream>  // needed for cout

// ContactInfo class declaration.
class ContactInfo
{
private:
	string name;		// The contact's name
	string phone;	// The contact's phone number
public:
	// Constructor
	ContactInfo(string n, string p)
   {  // Allocate memory for and copy the name and phone number.
      name = new string(n);
      phone = new string(p); 

   }

   // Destructor
   ~ContactInfo()
   { 
      delete name;
      delete phone; 
   }
   
   // Inline Accessor methods
	const string getName() const
   { return name; }

	const string getPhoneNumber() const
   { return phone; }
};
#endif 