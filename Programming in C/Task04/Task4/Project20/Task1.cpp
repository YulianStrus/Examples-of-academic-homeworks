#include "iostream"
using namespace std;
void main()
{
	float a, b;
	cout << "Enter the distance in miles ";
	cin >> a;
	a *= 1.609344;
	b = a * 0.539956803;
	cout << "Distance in kilometers = " << a << "\nDistance in sea miles = " << b << endl;
	system("pause");
}
