#include "iostream"
using namespace std;
int main()
{
	int k;
	float n, a, b;
	cout << "Input speed (km/h) ";
	cin >> a;
	cout << "Input speed (m/s) ";
	cin >> b;
	n = a / (b * 3.6);
	(n > 1) ? k = 2 : (n < 1 ? k = 0 : k = 1);
	switch (k)
	{
	case 0: cout << b << "m/s > " << a << "km/h" << endl; break;
	case 1: cout << a << "km/h = " << b << "m/s" << endl; break;
	case 2: cout << a << "km/h > " << b << "m/s" << endl; break;
	}
	system("pause");
	return 0;
}
