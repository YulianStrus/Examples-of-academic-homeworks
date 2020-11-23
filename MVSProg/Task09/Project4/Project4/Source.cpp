#include "iostream"
using namespace std;
int main()
{
	int	n, a, b, c, d, e;
	cout << "Input number (1 to 100000) ";
	cin >> n;
	if (n > 100000) cout << "Error" << endl;
	else if (n < 0) cout << "Error" << endl;
	else {
		e = n / 10000 - (n / 100000 * 10);
		d = n / 1000 - (n / 10000 * 10);
		c = n / 100 - (n / 1000 * 10);
		b = n / 10 - (n / 100 * 10);
		a = n - (n / 10 * 10);
		switch (e)
		{
		case 0: if (d > 0) (cout << " " << d << " " << c << " " << b << " " << a << endl); else if (c > 0) (cout << " " << c << " " << b << " " << a << " " << endl); else if (b > 0) (cout << " " << b << " " << a << " " << endl); else if (a > 0) (cout << " " << a << endl); else cout << "Error" << endl; break;
		case 1: cout << e << " " << d << " " << c << " " << b << " " << a << " " << endl; break;
		case 2: cout << e << " " << d << " " << c << " " << b << " " << a << " " << endl; break;
		case 3: cout << e << " " << d << " " << c << " " << b << " " << a << " " << endl; break;
		case 4: cout << e << " " << d << " " << c << " " << b << " " << a << " " << endl; break;
		case 5: cout << e << " " << d << " " << c << " " << b << " " << a << " " << endl; break;
		case 6: cout << e << " " << d << " " << c << " " << b << " " << a << " " << endl; break;
		case 7: cout << e << " " << d << " " << c << " " << b << " " << a << " " << endl; break;
		case 8: cout << e << " " << d << " " << c << " " << b << " " << a << " " << endl; break;
		case 9: cout << e << " " << d << " " << c << " " << b << " " << a << " " << endl; break;
		}
	}
	system("pause");
	return 0;
}
