#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void BigNum(int a, int b)
{
	if (a > b) cout << a << " > " << b;
	if (a < b) cout << b << " > " << a;
	if (a == b) cout << "a = b = " << a;
	cout << endl;
}
void main()
{
	int a, b;
	cout << "Enter first number: " << endl;
	cin >> a;
	cout << "Enter first number: " << endl;
	cin >> b;
	BigNum(a, b);


	system("pause");
}
