#include "iostream"
using namespace std;
void main()
{
	double a;
	cout << "Enter the number in inches ";
	cin >> a;
	a *= 0.0032808399;
	cout << "Number in centimeters = " << a << endl;
	system("pause");
}
