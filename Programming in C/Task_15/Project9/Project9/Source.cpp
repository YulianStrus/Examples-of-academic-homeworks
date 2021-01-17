#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void NumFunc(int a)
{
	if (a >= 0) cout << "true" << endl;
	else cout << "false" << endl;

}
void main()
{
	int a;
	cout << "Enter number: " << endl;
	cin >> a;

	NumFunc(a);


	system("pause");
}
