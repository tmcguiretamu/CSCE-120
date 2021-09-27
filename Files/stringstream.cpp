// This program lets the user pull off individual words in a string and display them.
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int main()
{
   ifstream inputFile;
   string filename, line, word;
   int number;

   // Get the filename from the user.
   cout << "Enter the filename: ";
   cin >> filename;

   // Open the file.
   inputFile.open(filename.c_str());

   // If the file successfully opened, process it.
   if (inputFile)
   {
      // Read the words from the file and
      // display them.
      while (!inputFile.eof())
      {
         getline(inputFile, line);
		 istringstream words(line);
		 while (words >> word)
		 {
			 cout << word << endl;
		 }
      }

      // Close the file.
      inputFile.close();
   }
   else
   {
	   // Display an error message.
	   cout << "Error opening the file.\n";
   }
   return 0;
}