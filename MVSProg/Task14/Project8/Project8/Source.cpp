#include "iostream"
using namespace std;
void main()
{
	int s, f, k = 1;
	cout << "Enter start string: " << endl;
	cin >> s;
	cout << "Enter finish string: " << endl;
	cin >> f;

	for (int i = s; i <= f; ++i)
	{
		int S = 0;
		for (int j = 1; j <= i; ++j)
			if (i % j == 0) ++S;
		if (S > k) k=S;
		else continue;
				
	}
	cout << k << endl;
	system("pause");
}
