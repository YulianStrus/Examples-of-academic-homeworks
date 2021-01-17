#include "iostream"
using namespace std;

unsigned long int FactNum(int x)
{
	if (x > 0) return x * FactNum(x-1);
	if (x == 0) return 1;
}

void main()
{
	int x;
	cout << "Enter number: " << endl;
	cin >> x;
	if (x > 33) cout << "Error!" << endl;
	else cout << x << "! = " << FactNum(x) << endl;

	system("pause");
}