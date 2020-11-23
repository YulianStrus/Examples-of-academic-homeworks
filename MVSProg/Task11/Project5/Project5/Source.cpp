#include "iostream"
using namespace std;
int main()
{
	int a; int i = 0;
	cout << "Enter a ";
	cin >> a;
while (a==0)
	{
	i = i + a;
	cout << i << endl << "Enter a ";
	cin >> a;
	}

	system("pause");
}
