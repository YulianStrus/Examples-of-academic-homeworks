#include "iostream"
using namespace std;
void main()
{
	double a, b, c, d;
	cout << "Enter the volume in bytes ";
	cin >> a;
	a *= 0.001;
	b = a * 0.001;
	c = b * 0.001;
	d = c * 0.001;
	cout << "Volume in kilobytes = " << a << "\nVolume in megabytes = " << b << "\nVolume in gigabytes = " << c << "\nVolume in terabytes = " << d << endl;
	system("pause");
}
