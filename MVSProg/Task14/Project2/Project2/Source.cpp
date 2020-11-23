#include "iostream"
using namespace std;
void main()
{
	int s, f;
	cout << "Enter start " << endl;
	cin >> s;
	cout << "Enter finish" << endl;
	cin >> f;
	int count;
	for (int i = s; i <= f; ++i)
	{
		count = 0;
		for (int j = 1; j <= i; ++j) 
			if (i % j == 0) ++count;
			if (count == 2) cout << i << " ";
	}

	system("pause");
}
