#include "iostream"
using namespace std;
void main()
{
	int sum;
	cout << "Input sum ";
	cin >> sum;
	if (sum % 2 == 0) cout << sum * 3 << endl; else cout << sum / 2.0 << endl;
	system("pause");
}
