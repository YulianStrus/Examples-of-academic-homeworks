#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void FactNumb(int a, int b)
{
	for (int i = 1; i <= a; i++)
		b *= i;
	if (a > 33) cout << "Error!" << endl;
	else cout << "Factorial of a natural number " << a << "= " << b << endl;
}
void main()
{

	int a;
	cout << "Enter number: " << endl;
	cin >> a;
	FactNumb(a, 1);


	system("pause");
}
