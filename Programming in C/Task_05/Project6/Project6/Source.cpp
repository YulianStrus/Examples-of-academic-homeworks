#include "iostream"
using namespace std;
void main()
{
	int  ca, cb, cc, n, x, y, A;

	//Завдання a:
	cout << "Enter the n-th member of the Fibonacci sequence. " << endl;
	cin >> n;
	int aa = 1, ba = 1, i = 2;
	do
	{
		ca = aa + ba;
		aa = ba;
		ba = ca;
		i++;
	} while (i <= n);
	ba = aa;
	cout << n << " member of the Fibonacci sequence = " << ca << "/" << ba << endl << endl;

	//Завдання b:
	cout << "Enter the n-th member of the Fibonacci sequence. " << endl;
	cin >> x;
	int ab = 1, bb = 1, j = 2;
	cout << n << " member of the Fibonacci sequence: " << endl;
	cout << ab << "/" << bb << endl;
	do
	{
		cb = ab + bb;
		cout << cb << "/" << bb << endl;
		ab = bb;
		bb = cb;
		j++;
	} while (j <= x);
	cout << endl;

	
	//Завдання c:
	cout << "Enter the n-th member of the Fibonacci sequence. " << endl;
	cin >> y;
	cout << "Enter member A: " << endl;
	cin >> A;
	float ac = 1, bc = 1, e = 2, Sum = 1;
	 
	do
	{
		cc = ac + bc;
		ac = bc;
		bc = cc;
		e++;
		Sum = Sum + (bc/ac);
	} while (e <= y);
	(Sum > A) ? cout << "Yes, number A > " << Sum << endl << endl : cout << "No, number A < " << Sum << endl << endl;


	system("pause");
}
