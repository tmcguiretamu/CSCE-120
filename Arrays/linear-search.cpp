// Linear (aka sequential) search
//Searches a partially filled array of nonnegative integers.
// Adapted from Walter Savitch, Problem Solving with C+++
#include <iostream>
const int CAPACITY = 20;

void fillArray(int a[], int maxSize, int& numberUsed);
//Precondition: maxSize is the declared capacity of the array a.
//Postcondition: numberUsed is the number of values stored in a.
//a[0] through a[numberUsed-1] have been filled with
//nonnegative integers read from the keyboard.

int search(const int a[], int numberUsed, int target);
//Precondition: numberUsed is <= the declared capacity of a.
//Also, a[0] through a[numberUsed -1] have values.
//Returns the first index such that a[index] == target,
//provided there is such an index; otherwise, returns -1.

int main( )
{
    using namespace std;
    int arr[CAPACITY], list_size, target;

    fillArray(arr, CAPACITY, list_size);

    char ans;
    int result;
    do
    {
        cout << "Enter a number to search for: ";
        cin >> target;

        result = search(arr, list_size, target);
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
//Uses iostream:
void fillArray(int a[], int maxSize, int& numberUsed)
{
    using namespace std;
    cout << "Enter up to " << maxSize << " nonnegative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";
    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < maxSize))
    {
        a[index] = next;
        index++;
        cin >> next;
    }

    numberUsed = index;
}

int search(const int a[], int numberUsed, int target)
{

    int index = 0;
    bool found = false;
    while ((!found) && (index < numberUsed))
        if (target == a[index])
            found = true;
        else
            index++;

    if (found)
        return index;
    else
        return -1;
}

