#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void PrintHello3(int a, int b) 
{
	for (int i = a; i <= b; ++i)
		cout << i << " ";
	cout << endl;
}
void main()
{
	//Варіант 1
	PrintHello3(3,6);
	cout << endl << endl;

	//Варіант 2
	int a = 4, b=9;
	PrintHello3(a,b); 
	cout << endl << endl;

	//Варіант 3
	cin >> a >> b;
	PrintHello3(0, b);
	PrintHello3(a, 12);

	system("pause");
}
