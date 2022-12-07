// Example using a for loop
#include <iostream>

using namespace std;

int main()
{
	int i;
/*	
	for (i = 0; i < 10; i++)
	{
		cout << i << "\t" << i*i << endl;
	}

	i = 0;
	for (;i < 10;)
	{
		cout << i << "\t" << i*i << endl;
		i++;
	}
	cout << "Done!" << endl;
*/
	int a = 10;
	int b = 3;
	
	do
	{
		cout << " a = " << a << "\t b = " << b << endl;
		a--;
	} while (a > b);
	
	return 0;
	
}
