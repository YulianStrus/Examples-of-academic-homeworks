#include "iostream"
using namespace std;

void NStar(int N)
{
	if (N > 0) return; cout << '*'; NStar(N - 1);
}

void main()
{
	int N;
	cout << "Enter number star: " << endl;
	cin >> N;
	NStar(N);

	system("pause");
}