#include "iostream"
using namespace std;
void main()
{
	int a, b;
	cout << "Enter start " << endl;
	cin >> a;
	cout << "Enter end " << endl;
	cin >> b;
	do
	{
		(cout << a << " ");
		a += 1;
	} while (a <= b);
	system("pause");
}