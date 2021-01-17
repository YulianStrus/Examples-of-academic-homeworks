#include "iostream"
#include "math.h"
using namespace std;
void main()
{
	double a, m, p;
	cout << "Enter the deposit amount ";
	cin >> a;
	cout << "Enter the deposit term in months ";
	cin >> m;
	cout << "Enter the interest rate ";
	cin >> p;
	for (int i = 0; i < m; i++)
	{
		a = a + ((a / 100)*(p / 12));
	};
	cout << "=" << a << endl;
	system("pause");
}
