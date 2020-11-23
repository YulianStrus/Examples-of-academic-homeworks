#include "iostream"
using namespace std;
void main()
{
	int a, b; char S;
	cout << "Enter a  " << endl;
	cin >> a;
	cout << "Enter a  " << endl;
	cin >> b;
	cout << "Enter symbol " << endl;
	cin >> S;
	int i = 1; int j = 1;
	while (true)
	{
		cout << S; ++i;
		if (i > a) {
			cout << endl;
			++j;
			i = 1;
		}
		if (j > b) break;
	}

	system("pause");
}
