#include "iostream"
using namespace std;

int SumNum(int x, int y)
{
	if (y == 0) return 1;
	if (y == 1) return x;
	return x + SumNum(x, y - 1);
}

void main()
{
	int x, y;
	cout << "Enter first number: " << endl;
	cin >> x;
	cout << "Enter second number: " << endl;
	cin >> y;
	cout << x << "*" << y << " = " << SumNum(x, y) << endl;

	system("pause");
}