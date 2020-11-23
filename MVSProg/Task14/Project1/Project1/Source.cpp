#include "iostream"
using namespace std;
void main()
{
	int h, l, i, j;
	char S;
	cout << "Enter number column " << endl;
	cin >> h;
	cout << "Enter number string " << endl;
	cin >> l;
	cout << "Enter symbol " << endl;
	cin >> S;
	for (i = 1; i <= l; i++)
	{
		for (j = 1; j <= h; j++)
			cout << S << " ";
		cout << endl;
	}
	
	system("pause");
}
