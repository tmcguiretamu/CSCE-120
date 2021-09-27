// binary search
//Searches a sorted filled array of nonnegative integers.

#include <iostream>
const int CAPACITY = 20;

int binarySearch(const int a[], int numberUsed, int target);
//Precondition: numberUsed is <= the declared capacity of a.
//Also, a[0] through a[numberUsed -1] have values, and are 
// arranged in increasing order.
//Returns the first index such that a[index] == target,
//provided there is such an index; otherwise, returns -1.

int main( )
{
    using namespace std;
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 42, 43, 47, 53, 59, 61, 67} ;
	int list_size = CAPACITY, target;
	// Note:  starting with C++17, you could say list_size = std::size(arr)  

    char ans;
    int result;
    do
    {
        cout << "Enter a number to search for: ";
        cin >> target;

        result = binarySearch(arr, list_size, target);
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


int binarySearch(const int a[], int size, int target)
{

    int first = 0,   		// First array element
		last = size - 1,	   // Last array element
		middle, 		         // Mid point of search
		index; 				   // Position of search value
	bool found = false;     // Flag 
    while ((!found) && (first <= last)) {
		middle = (first + last) / 2;     // Calculate mid point
        if (target == a[middle]) {
            found = true;
			index = middle;
		}
        else if (target < a[middle])	// target is in lower half
            last = middle -1; 
		else							// target is in upper half
			first = middle + 1;
	}
    if (found)
        return index;
    else
        return -1;	
}

