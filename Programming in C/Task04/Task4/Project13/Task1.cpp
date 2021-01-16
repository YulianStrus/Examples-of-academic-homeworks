#include "iostream"
using namespace std;
void main()
{
	double a, b, c, d;
	cout << "Enter the integer part ";
	cin >> a;
	cout << "Enter the numerator ";
	cin >> b;
	cout << "Enter the denominator ";
	cin >> c;
	d = a + (b / c);
	cout << "Decimal fraction =" << d << endl;
	system("pause");
}
