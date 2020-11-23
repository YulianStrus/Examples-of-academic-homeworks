#include "iostream"
using namespace std;
void main()
{
	
	for (int i = 120; i <= 140; ++i)
	{
		int S = 0;
		for (int j = 1; j <= i; ++j)
			if (i % j == 0) ++S;
		cout << i << " = " << S << endl;
	}

	system("pause");
}
