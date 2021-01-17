#include "iostream"
#define Max(a,b) a-b;
using namespace std;

void main()
{
	int a,b;
	cout << "Enter number:" << endl;
	cin >> a;
	cout << "Enter number:" << endl;
	cin >> b;
	int z = Max(a, b);
	if (z>0) cout << "a=" << a << " > " << "b=" << b << endl;
	else if (z < 0) cout << "b=" << b << " > " << "a=" << a << endl;
	else  cout << "a=" << a << " = " << "b=" << b << endl;	
	system("pause");
}