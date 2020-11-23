#include "iostream"
using namespace std;
void main()
{
	float a;
	cout << "Enter the number in inches ";
	cin >> a;
	a *= 2.54;
	cout << "Number in centimeters = " << a << endl;
	system("pause");
}
