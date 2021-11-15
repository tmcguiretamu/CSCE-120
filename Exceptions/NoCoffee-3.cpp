//Defining Your Own Exception Class
#include <iostream>
using namespace std;

class NoCoffeeException
{
public:
    NoCoffeeException();
    NoCoffeeException(int howMany);
    int getKolaches();
private:
    int count;
};

int main()
{
    int kolaches, coffee;
    double kpm;

    try
    {
        cout << "Enter number of kolaches:\n";
        cin >> kolaches;
        cout << "Enter number of mugs of coffee:\n";
        cin >> coffee;

        if (coffee <= 0)
               throw NoCoffeeException(kolaches);

        kpm = kolaches/static_cast<double>(coffee);
        cout << kolaches << " kolaches.\n"
             << coffee << " mugs of coffee.\n"
             << "You have " << kpm
             << " kolaches for each mug of coffee.\n";
    }
    catch(NoCoffeeException e)
    {
        cout << e.getKolaches() << " kolaches, and No Coffee!\n"
             << "Go buy some coffee.\n";
    }
    cout << "End of program.";
    return 0;
}

NoCoffeeException::NoCoffeeException()
{}

NoCoffeeException::NoCoffeeException(int howMany) : count(howMany)
{}

int NoCoffeeException::getKolaches()
{
    return count;
}


