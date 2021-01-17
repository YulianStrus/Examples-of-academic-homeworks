#include "iostream"
using namespace std;
void main()
{
	int i, j, c;

	for (i = 1; i < 10; ++i)
	{
		for (j = 1; j < 10; ++j)
		{
			c = j * i;
			cout << i << "x" << j << "=" << c << " \t";
		}
		cout << endl;
	}

	system("pause");
}
