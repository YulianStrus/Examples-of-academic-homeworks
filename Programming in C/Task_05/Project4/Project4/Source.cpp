#include "iostream"
using namespace std;
void main()
{
	int b;

	cout << "Enter assess students programming: " << endl;
	int a = 0, i = 9;
	do
	{
		--i;
		cin >> b;
		a = (a + b);
	} 
	while (i > 0);
	a = a / 9;
	cout << "Average rating for programming = " << a << endl << endl;
	
	cout << "Enter assess students ITEHaS: " << endl;
	int c = 0, n = 9;
	do
	{
		--n;
		cin >> b;
		c = (c + b);
	} 
	while (n > 0);
	c = c / 9;
	cout << "Average rating for ITEHaS = " << c << endl;

	system("pause");
}