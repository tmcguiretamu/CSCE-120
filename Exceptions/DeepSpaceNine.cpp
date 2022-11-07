//Catching Multiple Exceptions
#include <iostream>
#include <string>
using namespace std;

class NegativeNumber
{
public:
    NegativeNumber();
    NegativeNumber(string takeMeToYourCatchBlock);
    string getMessage();
private:
    string message;
};

class DivideByZero
{};

double klingonsFight(int jemHadar, int klingons);

int main()
{
   int jemHadar, klingons;
   double portion;


   try
   {
      cout << "Enter number of Jem'Hadar warriors:  ";
      cin >> jemHadar;
 
      cout << "How many Klingon warriors do you have?  ";
      cin >> klingons;

      portion = klingonsFight(jemHadar, klingons);

      cout << "Each Klingon must fight "
           << portion << " Jem'Hadar.\n";
    }
    catch(NegativeNumber e)
    {
       cout << "Cannot have a negative number of "
             << e.getMessage() << endl;
    }
    catch(DivideByZero)
    {
       cout << "Send for help.\n";
    }

    cout << "End of program.\n";
    return 0;
}

double klingonsFight(int jemHadar, int klingons)
{
   if (jemHadar < 0)
      throw NegativeNumber("Jem'Hadar");

   if (klingons < 0)
      throw NegativeNumber("Klingons");
   
   if (klingons != 0)
      return jemHadar/static_cast<double>(klingons);
   else
      throw DivideByZero();
}   

NegativeNumber::NegativeNumber()
{}

NegativeNumber::NegativeNumber(string takeMeToYourCatchBlock)
    : message(takeMeToYourCatchBlock)
 {}

string NegativeNumber::getMessage()
{
    return message;
}

