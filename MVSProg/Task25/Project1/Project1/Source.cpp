#include "iostream"
using namespace std;

int PowNum(int x, int y)
{
	if (y == 0) return 1;
	if (y == 1) return x;
	return x * PowNum(x, y - 1);
}

void main()
{
	int x, y;
	cout << "Enter number: " << endl;
	cin >> x;
	cout << "Enter the degree of the number: " << endl;
	cin >> y;
	cout << x << "^" << y << " = " << PowNum(x, y) << endl;

	system("pause");
}