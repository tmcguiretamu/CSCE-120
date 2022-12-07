#include <iostream>
using namespace std;

int main()
{
	double x = 0.0;
	
	for (int i = 0; i < 1000000000; i++)
	{
		x += 0.1;
	}
	cout << x << endl;
	return 0;
}