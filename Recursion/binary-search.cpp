// binary search
//Searches a sorted filled array of nonnegative integers.

#include <iostream>

int binarySearch(const int [], int, int, int);

int main( )
{
   using namespace std;
   int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 42, 43, 47, 53, 59, 61, 67} ;
	int list_size = std::size(arr), target;
	// Note:  for pre-C++17, would need to set list_size = 20 (or whatever the capacity is)  

    char ans;
    int result;
    do
    {
        cout << "Enter a number to search for: ";
        cin >> target;

        result = binarySearch(arr, 0, list_size-1, target);
        if (result == -1)
            cout << target << " is not on the list.\n";
        else
            cout << target << " is stored in array position "
                 << result << endl
                 << "(Remember: The first position is 0.)\n";

        cout << "Search again?(y/n followed by Return): ";
        cin >> ans;
    }while ((ans != 'n') && (ans != 'N'));

    cout << "End of program.\n";
    return 0;
}


//***************************************************************
// The binarySearch function performs a recursive binary search *
// on a range of elements of an integer array passed into the   *
// parameter array. The parameter first holds the subscript of  *
// the range's starting element, and last holds the subscript   *
// of the ranges's last element. The parameter target holds the *
// the search target. If the search target is found, its array  *
// subscript is returned. Otherwise, -1 is returned indicating  * 
// the target was not in the array.                             *
//***************************************************************

int binarySearch(const int array[], int first, int last, int target)
{
   int middle; // Mid point of search

   if (first > last)
      return -1;
   middle = (first + last)/2;
   if (array[middle]==target)
      return middle;
   if (array[middle]<target)
      return binarySearch(array, middle+1,last,target);
   else
      return binarySearch(array, first,middle-1,target);
}