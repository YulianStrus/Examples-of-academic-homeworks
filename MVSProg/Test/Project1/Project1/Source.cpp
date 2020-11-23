#include "iostream"
using namespace std;

void main()
{
	int var = 3;
	int v[3] = { 1,2,3 };
	int *p = &v[0];
	var = *(++p)*(*++p);
	cout << "Var=" << var << endl;
	system("pause");
}