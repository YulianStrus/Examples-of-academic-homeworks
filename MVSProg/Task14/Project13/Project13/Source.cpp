#include "iostream"
using namespace std;
void main()
{
	float a, b, c, d, k=0;
	for (d = 0; d <= 100; d += 10)
	{
		for (c = 0; c <= 100; c += 5)
		{
			for (b = 0; b <= 100; b += 2)
			{
				for (a = 0; a <= 100; a += 1)
				{
					if ((d + c + b + a) == 100)
					{
						k = k + 1; cout << "Method: " << k << "\t 10 Uah = " << d << "\t 5 Uah = " << c << "\t 2 Uah = " << b << "\t 1 Uah = " << a << endl;
					}
					else ++a;
				}
			}
		}
	}
	cout << k << endl;
	system("pause");
}
