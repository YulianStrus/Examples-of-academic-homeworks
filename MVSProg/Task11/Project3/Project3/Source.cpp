#include "iostream"
using namespace std;
int main()
{
	int i, a, b;
	cout << "Enter start " << endl;
	cin >> a;
	cout << "Enter finish " << endl;
	cin >> b;
	i = a;
	while (a <= b)
	{
		if (i / 3 == 0) i = i + a; i++;
	} //Not finish

	system("pause");
}
