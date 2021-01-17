#include "iostream"
using namespace std;
void main()
{
	int a;
	cout << "Input digit ";
	cin >> a;
	if (a > 0) cout << "The number is valid " << endl; else
		if (a == 0) cout << "The number is 0 " << endl; else cout << "The number is negative" << endl;
	system("pause");
}
