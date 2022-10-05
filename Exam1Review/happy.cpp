#include <iostream>
using namespace std;

bool isHappy(unsigned int);
int sumOfSquaredDigits(unsigned int);

int main()
{
/*	int n;
	cout << "Enter an unsigned integer: ";
	cin >> n;
	if (isHappy(n))
		cout << n << " is happy" << endl;
	else
		cout << n << " is NOT happy" << endl;
*/
	int count = 0;
	for(unsigned int i = 0; i < 1002; i++)
	{
		if (isHappy(i)) {
			cout << i << endl;
			++count;
		}
	}
	cout << "There are " << count << " happy numbers" << endl;   
  
	return 0;
}

bool isHappy(unsigned int num)
{
	unsigned int n = num;
	while (n != 4 && n != 1 && n != 0)
	{
		n = sumOfSquaredDigits(n);
	}
	return (n==1);
}

int sumOfSquaredDigits(unsigned int n)
{
	int sum = 0, digit;
	while (n > 0)
	{
		digit = n % 10;
		sum += digit * digit;
		n /= 10;
	}
	return sum;
}