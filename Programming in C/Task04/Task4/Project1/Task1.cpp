#include "iostream"
using namespace std;
void main()
{
	int a, b, c;
	cout << "Enter a ";
	cin	>> a;
	b = a * a;
	a *= b;
	c = b * b;
	cout << "a^2 = " << b << "  a^3 = " << a << "  a^4 = " << c << endl;
	system("pause");
}
