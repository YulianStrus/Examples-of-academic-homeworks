#include "iostream"
using namespace std;
void main()
{
	unsigned long int n, k=1, i;
	cout << "Enter number " << endl;
	cin >> n;
	for (i = 1; i <= n; i++)
	k *= i;
	if (n > 33) cout << "Error!" << endl;
	else cout << "Factorial of a natural number " << n << "= " << k << endl;
	system("pause");
}
