#include "iostream"
using namespace std;
void main()
{
	
	for (int i = 1; i <= 100000; ++i)
	{
		int k = 0, S;
		for (int j = 1; j <= i; ++j)
			if (i % j == 0)  k = k + j;
		if ((S=(k-i))==i)	cout << i << " = " << S << endl;
	}

	system("pause");
}
