#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

int NumSum(int a, int b)
{
	return (a + b);
}
int NumSub(int a, int b)
{
	return (a - b);
}
int NumMult(int a, int b)
{
	return (a * b);
}
int NumDiv(int a, int b)
{
	return (a / b);
}

void main()
{
	int a, b;
	char ch;
	cout << "Enter number: " << endl;
	cin >> a;
	cout << "Enter action: " << endl;
	cin >> ch;
	cout << "Enter number: " << endl;
	cin >> b;

	if (ch == '+') cout << NumSum(a, b) << endl;
	else if (ch == '-') cout << NumSub(a, b) << endl;
	else if (ch == '*') cout << NumMult(a, b) << endl;
	else if (ch == '/') cout << NumDiv(a, b) << endl;
	else cout << "Error!";


	system("pause");
}
