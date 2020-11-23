#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

int PrintOne()
{
	int a = 1;
	return a; 
}
void main()
{
	int a = PrintOne();
	cout << PrintOne();

	system("pause");
}
