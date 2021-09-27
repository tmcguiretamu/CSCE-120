// This program will input a file of integer values
// and output a file of with those values in reverse order.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;



int main()
{
   const int MAX = 20;
   ifstream inputFile;
   ofstream outputFile;
   string filename;
   int number, values[MAX], numVals;

   // Get the filename from the user.
   cout << "Enter the filename for input: ";
   cin >> filename;

   // Open the file.
   inputFile.open(filename.c_str());

   // If the file successfully opened, process it.
   if (inputFile)
   {
      // Read the numbers from the file 
	  numVals = 0;
      while ((numVals < MAX) && (inputFile >> number))
      {
         values[numVals] = number;
		 numVals++;
      }

      // Close the file.
      inputFile.close();
   }
   else
   {
	   // Display an error message.
	   cout << "Error opening the file.\n";
   }
   
/*  
   // Output the numbers in reverse order
   for(int i=numVals-1; i >= 0 ; i--)
   {
		cout << values[i] << "\n";
   }

*/
   // Get the filename from the user.
   cout << "Enter the filename for output: ";
   cin >> filename;

   // Open the file.
   outputFile.open(filename.c_str());

   // If the file successfully opened, process it.
   if (outputFile)
   {
      // Write the numbers to the file 
	  for(int i=numVals-1; i >= 0 ; i--)
      {
         outputFile << values[i] << "\n";
      }

      // Close the file.
      outputFile.close();
   }
   else
   {
	   // Display an error message.
	   cout << "Error creating the file.\n";
   } 
}


   