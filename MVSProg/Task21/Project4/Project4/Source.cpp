#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void PrintBiggest(int a, int b)
{
	if (a > b) cout << a;
	if (a < b) cout << b;
	if (a == b) cout << "a=b=" << a;
	cout << endl;
}
void main()
{
	//Варіант 1
	PrintBiggest(3, 6);
	cout << endl << endl;

	//Варіант 2
	int a = 4, b = 9;
	PrintBiggest(a, b);
	cout << endl << endl;

	//Варіант 3
	cin >> a >> b;
	PrintBiggest(0, b);
	PrintBiggest(a, 12);

	system("pause");
}
