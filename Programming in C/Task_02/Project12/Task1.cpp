#include "iostream"
using namespace std;
void main()
{
	double a, b, c, d, x, y, w, z;
	cout << "Enter the numerator of the first number ";
	cin >> a;
	cout << "Enter the denominator of the first number ";
	cin >> b;
	cout << "Enter the numerator of the number ";
	cin >> c;
	cout << "Enter the denominator of the second number ";
	cin >> d;
	x = (a / b) + (c / d);
	y = (a / b) - (c / d);
	w = (a / b) * (c / d);
	z = (a / b) / (c / d);
	cout << "The amount of fractions = " << x << "\nThe difference in fractions = " << y << "\nThe product of fractions = " << w << "\nQuotient = " << z << endl;
	system("pause");
}
