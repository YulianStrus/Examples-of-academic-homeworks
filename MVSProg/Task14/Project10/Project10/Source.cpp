#include "iostream"
using namespace std;
void main()
{
	int k = 1;
	for (int i = 0; i <= 1000; ++i)
	{
		int count = 0;
		for (int j = 1; j <= i; ++j)
			if (i % j == 0) ++count;
		if (count == 2)
			if ((i / 100 >= 1)& (i / 100 <= 10))  cout << i << " ";

	}
	system("pause");
}
