#include "iostream"
using namespace std;
int main()
{
	int a, b;
	cout << "Enter start " << endl;
	cin >> a;
	cout << "Enter finish " << endl;
	cin >> b;
	while (a <= b)
	{
		(cout << a << " ");
		a += 1;
	} 

	system("pause");
}
