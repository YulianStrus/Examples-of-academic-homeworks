#include "iostream"
using namespace std;
void main()
{
	int i = 1, k;
	cout << "Enter number: " << endl;
	cin >> k;
	for (i; i <= k; i++)
	{
		if (k % i == 0)	cout << i << " ";
	}
		

	system("pause");
}
