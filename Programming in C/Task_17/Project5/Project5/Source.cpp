#include "iostream"
using namespace std;

int SumNum(int a, int b)
{
	if (a < b) return a + SumNum(a + 1, b);
}

void main()
{
	int a, b;
	cout << "Enter start number: " << endl;
	cin >> a;
	cout << "Enter end number: " << endl;
	cin >> b;
	cout << "Sum number from " << a << " to " << b << " = " << SumNum(a, b) << endl;

	system("pause");
}