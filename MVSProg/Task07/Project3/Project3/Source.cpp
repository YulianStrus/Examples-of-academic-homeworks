#include "iostream"
using namespace std;
void main()
{
	int sum;
	cout << "Input sum ";
	cin >> sum;
	if (sum < 100) cout << sum + sum * 0.00 << endl; else
		if ((sum >= 100) & (sum < 500)) cout << sum + sum * 0.02 << endl; else
			if ((sum >= 500) & (sum < 1000)) cout << sum + sum * 0.05 << endl; else
				if ((sum >= 1000) & (sum < 5000)) cout << sum + sum * 0.1 << endl; else
	if (sum > 5000) cout << sum + sum * 0.2 << endl;
	system("pause");
}
