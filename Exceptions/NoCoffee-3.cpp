//Defining Your Own Exception Class
#include <iostream>
using namespace std;

class NoCoffeeException
{
public:
   NoCoffeeException(int howMany);
   int getKolaches();
private:
   int count;
};

double kolachesPerMug(int kolaches, int coffee);

int main()
{
   int kolaches, coffee;
   double kpm;

   try
   {
      cout << "Enter number of kolaches:  ";
      cin >> kolaches;
      cout << "Enter number of mugs of coffee:  ";
      cin >> coffee;

      kpm = kolachesPerMug(kolaches, coffee);
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


double kolachesPerMug(int kolaches, int coffee)
{
   if (coffee <= 0)
   {
      throw NoCoffeeException(kolaches);   
   }
   else
   {
      return kolaches/static_cast<double>(coffee); 
   }
}


NoCoffeeException::NoCoffeeException(int howMany) 
{
   count = howMany;
}

int NoCoffeeException::getKolaches()
{
    return count;
}


