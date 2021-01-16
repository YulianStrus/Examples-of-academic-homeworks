#include "iostream"
using namespace std;
void main()
{
	int a, b, c;
	cout << "Enter a two-digit number ";
	cin >> a;
	b = a / 10;
	c = a / 100;
	cout << "Number of ten entered numbers = " << b << "\nNumber of hundreds of entered numbers = " << c << endl;
	system("pause");
}
