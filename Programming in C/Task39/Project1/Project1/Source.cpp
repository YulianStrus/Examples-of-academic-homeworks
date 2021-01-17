#include "iostream"
#define Kub(a) a*a*a;
using namespace std;

void main()
{
	int z;
	cout << "Enter number:" << endl;
	cin >> z;
	int a = Kub(z);
	cout << "Kub = " << a << endl;
	system("pause");
}