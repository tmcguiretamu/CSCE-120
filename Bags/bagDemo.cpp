// FILE: bagdemo.cpp
// Demonstration program for the Bag class

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "bag.h"       // With Item defined as an int
using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void get_ages(Bag& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members. These ages have been read and placed in the ages bag, stopping
// when the user types a negative number.

void check_ages(Bag& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members once again. Each age is removed from the ages bag when it is typed,
// stopping when the bag is empty.


int main( )
{
    Bag ages;

    get_ages(ages);
    check_ages(ages);
    cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;  
}


void get_ages(Bag& ages)
{
    int user_input; // An age from the user's family

    cout << "Type the ages in your family. ";
    cout << "Type a negative number when you are done:" << endl;
    cin >> user_input;
    while (user_input >= 0)
    {
        ages.insert(user_input);
        cin >> user_input;
    }
}

void check_ages(Bag& ages)
{
    int user_input; // An age from the user's family

    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size( ) > 0)
    {
        cin >> user_input;
        if (ages.erase_one(user_input))
            cout << "Yes, I've got that age and have removed it." << endl;
        else
            cout << "No, that age does not occur!" << endl;
    }
}
