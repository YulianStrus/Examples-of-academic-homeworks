#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void PrintHello3(int a) //а - локальна змінна або формальний параметр
{
	for (int i=1; i<=a;++i)
	cout << "Hello!" << endl;
}
void main()
{
	//Варіант 1
	PrintHello3(5);
	cout << endl << endl;

	//Варіант 2
	int a = 7;
	PrintHello3(a); //а - глобальна змінна або фактичний параметр
	cout << endl << endl;

	//Варіант 3
	cin >> a;
	PrintHello3(a);

	system("pause");
}
