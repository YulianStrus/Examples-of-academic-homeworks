#include "iostream"
using namespace std;
void main()
{
	float a, b; char ch;
	cout << "Input first digit ";
	cin >> a;
	cout << "Input second digit ";
	cin >> b;
	cout << "Enter an arithmetic action ";
	cin >> ch;
	if (ch == '+') cout << a + b << endl; else
		if (ch == '-') cout << a - b << endl; else
			if (ch == '*') cout << a * b << endl; else
				if (ch == '/') cout << a / b << endl;
	system("pause");
}
