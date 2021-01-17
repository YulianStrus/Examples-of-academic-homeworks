#include "iostream"
using namespace std;
void main()
{
	int  ca, cb, cc, cd, ce, cf, n, k, x, y, m;

	//Завдання a:
	cout << "Enter the n-th member of the Fibonacci sequence. " << endl;
	cin >> n;
	int aa = 1, ba = 1, i = 3;

	do
	{
		ca = aa + ba;
		aa = ba;
		ba = ca;
		i++;
	} while (i <= n);
	cout << n << " member of the Fibonacci sequence = " << ca << endl << endl;

	//Завдання b:
	cout << "Enter the n-th member of the Fibonacci sequence. " << endl;
	cin >> k;
	int ab = 1, bb = 1;
	do
	{
		cb = ab + bb;
		ab = bb;
		bb = cb;
	} while (cb < k);
	cout << "The first number in the Fibonacci sequence, greater than n = " << cb << endl << endl;

	//Завдання c:
	int ac = 1, bc = 1, Sum = 2;
	do
	{
		cc = ac + bc;
		ac = bc;
		bc = cc;
		Sum = Sum + cc;
	} while (cc < 1000);
	Sum = Sum - cc;
	cout << "The sum of all numbers in the Fibonacci sequence < 1000 = " << Sum << endl;

	//Завдання d:
	cout << "Enter the n-th member of the Fibonacci sequence. " << endl;
	cin >> x;
	int ad = 1, bd = 1, j = 3;
	cout << "The first " << x << " terms of the Fibonacci sequence: " << endl;
	cout << ad << " ";
	cout << bd << " ";
	do
	{
		cd = ad + bd;
		ad = bd;
		bd = cd;
		cout << cd << " ";
		j++;
	} while (j <= x);
	cout << endl;

	//Завдання e:
	cout << "Enter the n-th member of the Fibonacci sequence. " << endl;
	cin >> y;
	int ae = 1, be = 1, e = 3, Summ = 2;

	do
	{
		ce = ae + be;
		ae = be;
		be = ce;
		e++;
		Summ = Summ + ce;
	} while (e <= y);
	(Summ % 2 == 0) ? cout << "Yes" << endl << endl : cout << "No" << endl << endl;

	//Завдання f:
	cout << "Enter the n-th member of the Fibonacci sequence. " << endl;
	cin >> m;
	int af = 1, bf = 1, z = 3, w = 1, l = 0;

	do
	{
		cf = af + bf;
		af = bf;
		bf = cf;
		z++;
	} while (z <= m);
	
	do {
		if (cf%w == 0)++l; ++w;
	} while (w <= cf);
	if (l == 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	


	system("pause");
}