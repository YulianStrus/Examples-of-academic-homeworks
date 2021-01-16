#include "iostream"
using namespace std;
void main()
{
	int k, a, b, c; float S, P, T;
	cout << "Enter a three-digit number ";
	cin >> k;
	a = k / 100;
	b = (k / 10) - (a * 10);
	c = k - (a * 100 + b * 10);
	S = a + b + c;
	P = a * b*c;
	T = S / 3;
	cout << "Number  one = " << a << "\nNumber two = " << b << "\nNumber three = " << c << "\nSum of numbers = " << S << "\nThe product of numbers = " << P << "\nAverage arithmetic numbers = " << T << endl;
	system("pause");
}
