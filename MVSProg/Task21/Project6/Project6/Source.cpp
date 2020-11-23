#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

double SomeFunc(int a)
{
	++a;
	double b = a / 7;
	return (b + sin(a))*cos(a + b);
}
void main()
{
	double a = SomeFunc(4);
	int b = 7;
	cout << a << endl;
	a = SomeFunc(b);
	cout << a << endl;

	system("pause");
}
