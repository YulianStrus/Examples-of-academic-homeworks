#include "iostream"
using namespace std;
void main()
{
	float a;
	cout << "Enter the distance in miles ";
	cin >> a;
	a *= 1609.344;
	cout << "Distance in meters = " << a << endl;
	system("pause");
}
