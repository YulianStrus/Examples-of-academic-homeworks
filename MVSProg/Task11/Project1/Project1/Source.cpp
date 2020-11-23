#include "iostream"
using namespace std;
int main()
{
	int a; int i = 0;
	cout << "Enter number " << endl;
	cin >> a;
	while (i <= a)
	{
		(cout << i << " ");
		i += 1;
	}

	system("pause");
}
