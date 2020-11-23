#include "iostream"
using namespace std;
int main()
{
	int a, b, r; char c;
	cout << "Input firt number ";
	cin >> a;
	cout << "Input second number ";
	cin >> b;
	cout << "Input second number ";
	cin >> c;
	switch (c)
	{
	case '+': r = a + b; cout << r << endl; break;
	case '-': r = a - b; cout << r << endl; break;
	case '*': r = a * b; cout << r << endl; break;
	case '/': r = a / b; cout << r << endl; break;
	default: r = 0; cout << "ERROR Symbol" << endl;
	}
	system("pause");
	return 0;
}