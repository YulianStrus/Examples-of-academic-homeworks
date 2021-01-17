#include "iostream"
using namespace std;
void main()
{
	int s, f, n=0, i=1, j=1;
	cout << "Enter start " << endl;
	cin >> s;
	cout << "Enter finish " << endl;
	cin >> f;

	for (i = s; i <= f; i++)
	{
		for (j = s; j <= f; j++)
			if (j == n)
			{
				cout << "Number entered correctly!" << endl;
			}
			else continue;

			cout << "Enter number " << endl; cin >> n;
	}
	system("pause");
}
