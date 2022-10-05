#include <iostream>
using namespace std;

/*
	Given n > 0 and a sequence of ninteger numbers, print how many segments composed by  consecutive copies of the same number the sequence has. 
	For example: The sequence
		5 2 2 3 4 4 4 4 1 1 1
	has 5 segments.
*/

int numSegments(const int [], const int) ;

int main() {
	const int SIZE = 12;
	int a[SIZE] = { 5, 2, 2, 3, 4, 4, 6, 4, 4, 1, 1, 1};
	
	cout << "The number of segments is " << numSegments(a, SIZE) << endl;
	return 0;
}

int numSegments(const int x[], const int size) {
	int count = 0;
	for (int i = 1; i < size; i++)
		if (x[i-1] != x[i]) count++;
   
	return ++count;
}
	
	
