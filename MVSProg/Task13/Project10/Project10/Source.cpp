#include "iostream"
using namespace std;
void main()
{
	int i = 1, a, k, b=0;
	cout << "Enter stop number: " << endl;
	cin >> a; 
	cout << "Enter number: " << endl;
	cin >> k;
	for (i; i <= a; i++)
	{
		if (i % k == 0) 
		{
			cout << i << " ";
			b++;
		}
	}
	cout << endl << b << " numbers from 1 to " << a << " times " << k << endl;

	system("pause");
}
