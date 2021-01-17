#include "iostream"
using namespace std;
void main()
{
	int a, b;
	cout << "Input first digit ";
	cin >> a;
	cout << "Input second digit  ";
	cin >> b;
	if (a == b) cout << "These numbers are equal" << endl; else
		if (a < b) cout << a <<", "<< b << endl; else cout << b << ", "<< a << endl;
	system("pause");
}
