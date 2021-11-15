// Handling a Special Case Without Exception Handling
#include <iostream>
using namespace std;

int main()
{
    int kolaches, coffee;
    double kpm;            // kolaches per mug
    
    cout << "Enter number of kolaches:\n";
    cin >> kolaches;
    cout << "Enter number of mugs of coffee:\n";
    cin >> coffee;

    if (coffee <= 0)
    {
        cerr << kolaches << " kolaches, and No Coffee!\n"
              << "Go buy some coffee.\n";
    }
    else
    {
        kpm = kolaches/static_cast<double>(coffee);
        cout << kolaches << " kolaches.\n"
              << coffee << " mugs of coffee.\n"
              << "You have " << kpm
              << " kolaches for each mug of coffee.\n";
    }

    cout << "End of program.\n";
    return 0;
}
