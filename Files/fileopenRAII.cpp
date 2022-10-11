// This program lets the user enter a filename.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
   string filename;
   int number;

   // Get the filename from the user.
   cout << "Enter the filename: ";
   cin >> filename;

   // Open the file.
   ifstream inputFile(filename);
   // If the file successfully opened, process it.
   if (inputFile.is_open())
   {
      // Read the numbers from the file and
      // display them.
      while (inputFile >> number)
      {
         cout << number << endl;
      }

      // The file closes automatically.
   }
   else
   {
	   // Display an error message.
	   cout << "Error opening the file.\n";
   }
   return 0;
}