#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

double KybFunc(int a)
{
	return(a*a*a);
}
void main()
{
	int a;
	cout << "Enter number: " << endl;
	cin >> a;
	a = KybFunc(a);
	cout << "Kyb a= " << a << endl;
	system("pause");
}
