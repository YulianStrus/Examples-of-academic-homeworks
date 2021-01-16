#include "iostream"
using namespace std;
void main()
{
	int j = 1, a, k;
	cout << "Enter a step: " << endl;
	cin >> k;
	cout << "Enter number column: " << endl;
	cin >> a;
	for (int i=100;i<1000;i+=k)
	{
		if (j <= a) { cout << i << " "; ++j; }
		else {
			cout << endl; j = 1;
		}
	}
		
	system("pause");
}
