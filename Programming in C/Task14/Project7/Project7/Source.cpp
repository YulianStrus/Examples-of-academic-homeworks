#include "iostream"
using namespace std;
void main()
{
	int s, f, k;
	cout << "Enter start string: " << endl;
	cin >> s;
	cout << "Enter finish string: " << endl;
	cin >> f;
	cout << "Enter the number of dividers: " << endl;
	cin >> k;

	for (int i = s; i <= f; ++i)
	{
		int S = 0;
		for (int j = 1; j <= i; ++j)
			if (i % j == 0) ++S;
		if (S==k)	cout << i << " = " << S << endl;
	}

	system("pause");
}
