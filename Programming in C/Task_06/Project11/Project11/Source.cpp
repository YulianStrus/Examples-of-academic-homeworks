#include "iostream"
using namespace std;
void main()
{
	int x, y, a, b=1;
	cout << "Enter number: " << endl;
	cin >> x;
	cout << "Enter number: " << endl;
	cin >> y;
	
		(x < y) ? (a = x) : (a = y);

		for (int i = 1; i <= a; i++)
			if ((x%i == 0) && (y%i == 0)) b = (x*y) / i;		
			cout << b << endl;
	system("pause");
}
