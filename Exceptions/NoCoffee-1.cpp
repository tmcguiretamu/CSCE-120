// Handling a Special Case Without Exception Handling
#include <iostream>
#include <cstdlib>

using namespace std;

double kolachesPerMug(int kolaches, int coffee);

int main()
{
    int kolaches, coffee;
    double kpm;            // kolaches per mug
    
    cout << "Enter number of kolaches:  ";
    cin >> kolaches;
    cout << "Enter number of mugs of coffee:  ";
    cin >> coffee;

   kpm = kolachesPerMug(kolaches, coffee);
   cout << kolaches << " kolaches.\n"
        << coffee << " mugs of coffee.\n"
        << "You have " << kpm
        << " kolaches for each mug of coffee.\n";

    cout << "End of program.\n";
    return 0;
}

double kolachesPerMug(int kolaches, int coffee)
{
    if (coffee <= 0)
    {
        cerr << kolaches << " kolaches, and No Coffee!\n"
              << "Go buy some coffee.\n";
         exit(1);     
    }
    else
    {
        return kolaches/static_cast<double>(coffee); 
    }
}
