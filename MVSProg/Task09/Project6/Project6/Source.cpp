#include "iostream"
using namespace std;
int main()
{
	int n, a, b, c, s;
	cout << "Input mounth number ";
	cin >> n;
	a = n / 100;
	b = (n / 10) - (n / 100 * 10);
	c = n - (n / 10 * 10);

	switch (a)
	{
	case 1: (a + b + c) >= 10 ? cout << "Sum of numbers is a two-digit number= " << a + b + c << endl : cout << "sum of numbers is not a two-digit number= " << a + b + c << endl; break;
	case 2: (a + b + c) >= 10 ? cout << "Sum of numbers is a two-digit number= " << a + b + c << endl : cout << "sum of numbers is not a two-digit number= " << a + b + c << endl; break;
	case 3: (a + b + c) >= 10 ? cout << "Sum of numbers is a two-digit number= " << a + b + c << endl : cout << "sum of numbers is not a two-digit number= " << a + b + c << endl; break;
	case 4: (a + b + c) >= 10 ? cout << "Sum of numbers is a two-digit number= " << a + b + c << endl : cout << "sum of numbers is not a two-digit number= " << a + b + c << endl; break;
	case 5: (a + b + c) >= 10 ? cout << "Sum of numbers is a two-digit number= " << a + b + c << endl : cout << "sum of numbers is not a two-digit number= " << a + b + c << endl; break;
	case 6: (a + b + c) >= 10 ? cout << "Sum of numbers is a two-digit number= " << a + b + c << endl : cout << "sum of numbers is not a two-digit number= " << a + b + c << endl; break;
	case 7: (a + b + c) >= 10 ? cout << "Sum of numbers is a two-digit number= " << a + b + c << endl : cout << "sum of numbers is not a two-digit number= " << a + b + c << endl; break;
	case 8: (a + b + c) >= 10 ? cout << "Sum of numbers is a two-digit number= " << a + b + c << endl : cout << "sum of numbers is not a two-digit number= " << a + b + c << endl; break;
	case 9: (a + b + c) >= 10 ? cout << "Sum of numbers is a two-digit number= " << a + b + c << endl : cout << "sum of numbers is not a two-digit number= " << a + b + c << endl; break;
	default: cout << "It's not number " << endl;
	}
	system("pause");
	return 0;
}
