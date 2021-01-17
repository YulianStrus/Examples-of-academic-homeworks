#include "Header.h"
void EvenNum(int a)
{
	if (a % 2 == 0) cout << "Yes! This number is a pair" << endl;
	else cout << "No! This number is not even" << endl;
}
void SimpNum(int a)
{
	int k = 0;
	for (int i = 1; i <= a; i++)
	{
		if ((a % i) == 0)
			k++;
	}
	if (k == 2)	cout << "Yes! This number is simple" << endl;
	else cout << "No! This number is not simple" << endl;
}
void PerfectNum(int a, int b)
{
	for (int i = a; i <= b; ++i)
	{
		int k = 0, S;
		for (int j = 1; j <= i; ++j)
			if (i % j == 0)  k = k + j;
		if ((S = (k - i)) == i)	cout << S << " ";
	}
}