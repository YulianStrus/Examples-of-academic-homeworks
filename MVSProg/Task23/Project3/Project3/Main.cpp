#include "Header.h"
int main()
{
	int a, b;
	cout << "Enter number: " << endl;
	cin >> a;
	EvenNum(a);
	cout << endl;

	cout << "Enter number: " << endl;
	cin >> b;
	SimpNum(b);
	cout << endl;

	cout << "Enter number: " << endl;
	cin >> a;
	cout << "Enter number: " << endl;
	cin >> b;
	cout << "Perfect number: "; PerfectNum(a, b);
	cout << endl;


	system("pause");
}