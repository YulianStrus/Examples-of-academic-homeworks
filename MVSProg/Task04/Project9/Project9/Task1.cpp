#include "iostream"
#include "math.h"
using namespace std;
void main()
{
	double a, c;
	cout << "Enter number ";
	cin >> a;
	int b = a;
	c = (a - b) * 100;
	cout << "The whole part of the number = " << b << "\nFractional part of the number = " << c << endl;
	system("pause");
}
