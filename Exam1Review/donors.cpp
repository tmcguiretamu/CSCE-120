#include <iostream>
using namespace std;

void bestDonor(int kelly[], int sarah[]);


int main()
{
	int sarah[] = {100, 200, 50, 100, 100, 51, -10};
	int kelly[] = {100, 100, 100, 100, 100, 100, 100, 100, -40};
	
	bestDonor(kelly, sarah);
	
	return 0;
}

void bestDonor(int kellyDonations[], int sarahDonations[])
{
	int kellyCount = 0, sarahCount = 0, kellySum = 0, sarahSum = 0;
    double kellyAvg = 0.0, sarahAvg = 0.0;
	bool kellyQual, sarahQual;
	
	while(kellyDonations[kellyCount] >= 0)
	{
		kellySum += kellyDonations[kellyCount];
		++kellyCount;
	}
	if (kellyCount > 0) kellyAvg = (double) kellySum / kellyCount;
	
	while(sarahDonations[sarahCount] >= 0)
	{
		sarahSum += sarahDonations[sarahCount];
		++sarahCount;
	}	
	if (sarahCount > 0) sarahAvg = (double) sarahSum / sarahCount;
	
	kellyQual = (kellyCount >= 5) && (kellySum >= 300);
	sarahQual = (sarahCount >= 5) && (sarahSum >= 300);
	
	if (kellyQual) 
	{
		if (!sarahQual || kellyAvg > sarahAvg)
			cout << "Kelly wins" << endl;
		else if (kellyAvg == sarahAvg)
		{
			if (kellyCount > sarahCount)
				cout << "Kelly wins" << endl;
			else if (kellyCount == sarahCount)
				cout << "Kelly & Sarah tie" << endl;
			else
				cout << "Sarah wins" << endl;
		}
		else
			cout << "Sarah wins" << endl;
	}
	else if(sarahQual)
		cout << "Sarah wins" << endl;
	else
		cout << "Neither Kelly nor Sarah qualify for the prize" << endl;
	
	cout << "Done..." << endl;
	
}
		