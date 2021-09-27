// This program illustrates the use of runtime exceptions
#include <iostream>     // for cin/cout
#include <string>       // to use string class
#include <fstream>      // ifstream    
#include <stdexcept>    // runtime_exception
#include <cstdlib>      // exit()
using namespace std;

// function prototype
ifstream openFile(string filename);

int main()
{
   ifstream inputFile;
   string filename;
   int number;

   // Get the filename from the user.
   cout << "Enter the filename: ";
   cin >> filename;

   // Open the file.
   try 
   {
      inputFile = openFile(filename);
   }
   catch (runtime_error& excpt)
   {
      cout << excpt.what() << endl;
      exit(1);
   }

   // If the file successfully opened, process it.
   // Read the numbers from the file and
   // display them.
   while (inputFile >> number)
   {
      cout << number << endl;
   }
   // Close the file.
   inputFile.close();

   return 0;
}

// opens a file and returns an input stream attached to it
ifstream openFile(string filename)
{
   ifstream infile(filename);
   if (infile.is_open()) 
      return infile;
   else
       throw runtime_error("Failed to open file " + filename);
}