#include "iostream"
using namespace std;
int main()
{
	int n, a, b, c;
	cout << "Input mounth number ";
	cin >> n;
	a = n / 100;
	b = (n / 10) - (n / 100 * 10);
	c = n - (n / 10 * 10);

	switch (a)
	{
	case 1: (a == b) && (c == a) ? cout << "all numbers are the same " << endl : cout << a << " " << b << " " << c << endl; break;
	case 2: (a == b) && (c == a) ? cout << "all numbers are the same " << endl : cout << a << " " << b << " " << c << endl; break;
	case 3: (a == b) && (c == a) ? cout << "all numbers are the same " << endl : cout << a << " " << b << " " << c << endl; break;
	case 4: (a == b) && (c == a) ? cout << "all numbers are the same " << endl : cout << a << " " << b << " " << c << endl; break;
	case 5: (a == b) && (c == a) ? cout << "all numbers are the same " << endl : cout << a << " " << b << " " << c << endl; break;
	case 6: (a == b) && (c == a) ? cout << "all numbers are the same " << endl : cout << a << " " << b << " " << c << endl; break;
	case 7: (a == b) && (c == a) ? cout << "all numbers are the same " << endl : cout << a << " " << b << " " << c << endl; break;
	case 8: (a == b) && (c == a) ? cout << "all numbers are the same " << endl : cout << a << " " << b << " " << c << endl; break;
	case 9: (a == b) && (c == a) ? cout << "all numbers are the same " << endl : cout << a << " " << b << " " << c << endl; break;
	default: cout << "Error " << endl;
	}
	system("pause");
	return 0;
}
