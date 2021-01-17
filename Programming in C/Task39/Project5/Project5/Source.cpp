#include "iostream"
#define Min(a,b) a-b;
using namespace std;

void main()
{
	int a, b, c;
	cout << "Enter number:" << endl;
	cin >> a;
	cout << "Enter number:" << endl;
	cin >> b;
	cout << "Enter number:" << endl;
	cin >> c;
	int x = Min(a, b);
	int y = Min(b, c);
	int z = Min(a, c);
	if (x < 0) 
	{
		if (z < 0) cout << "min = " << a << endl;
		else cout << "min = " << c << endl;
	}
	else if (y < 0) cout << "min = " << b << endl;
	else cout << "min = " << c << endl;

	system("pause");
}