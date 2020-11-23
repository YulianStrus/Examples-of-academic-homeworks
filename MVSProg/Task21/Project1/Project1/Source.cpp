#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void PrintHello()
{
	cout << "Hello!" << endl;
}
void main()

{
	PrintHello();

	for (int i = 1; i <= 5; i++)
		PrintHello();

	system("pause");
}
