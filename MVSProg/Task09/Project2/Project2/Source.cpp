#include "iostream"
using namespace std;
int main ()
{
	int n;
	cout << "Input mounth number ";
	cin >> n;
	switch (n)
	{
		case 1:
		case 2:
		case 12: cout << "Winter" << endl; break;

		case 3:
		case 4:
		case 5: cout << "Spring" << endl; break;

		case 6:
		case 7:
		case 8: cout << "Summer" << endl; break;

		case 9:
		case 10:
		case 11: cout << "Authem" << endl; break;
		default: cout << "It's not number";
	}
	system ("pause");
	return 0;
}