#include "iostream"
using namespace std;
void main()
{
	int a, b;
	cout << "Please first digit ";
	cin >> a;
	cout << "Please second digit ";
	cin >> b;
	if (a < b) cout << a << endl; else cout << b << endl;
	system("pause");
}