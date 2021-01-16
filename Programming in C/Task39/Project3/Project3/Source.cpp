#include "iostream"
#define Sum(a,b,c) a+b+c;
using namespace std;

void main()
{
	int a, b, c;
	cout << "Enter number:" << endl;
	cin >> a;
	cout << "Enter number:" << endl;
	cin >> b;
	cout << "Enter number:" << endl;
	cin >> c;
	int z = Sum(a,b,c);
	cout << "Sum = " << z << endl;
	system("pause");
}