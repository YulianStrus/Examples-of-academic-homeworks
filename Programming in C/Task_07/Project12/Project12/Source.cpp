#include "iostream"
using namespace std;
void main()
{
	int i1, i2, S1, S2;
	for (i1 = 1; i1 <= 50000; ++i1)
	{
		int k1 = 0;
		for (int j1 = 1; j1 <= i1; ++j1)
			if (i1 % j1 == 0)  k1 = k1 + j1;
		(S1 = (k1 - i1));

		for (i2 = 1; i2 <= 50000; ++i2)
		{
			int k2 = 0;
			for (int j2 = 1; j2 <= i2; ++j2)
				if (i2 % j2 == 0)  k2 = k2 + j2;
			(S2 = (k2 - i2));

			if (((i1 == S2)&(i1!=S1))&((i2 == S1)&(i2!=S2))) 	cout << i1 << " and " << i2 << endl;
		}
	}
	system("pause");
}
