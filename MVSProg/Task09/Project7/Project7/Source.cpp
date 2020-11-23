#include "iostream"
using namespace std;
int main()
{
	int n;
	cout << "Input weekday number ";
	cin >> n;
	switch (n)
	{
	case 1: cout << "Workday" << endl; break;
	case 2: cout << "Workday" << endl; break;
	case 3: cout << "Workday" << endl; break;
	case 4: cout << "Workday" << endl; break;
	case 5: cout << "Workday" << endl; break;
	case 6: cout << "Saturday" << endl; break;
	case 7: cout << "Sunday" << endl; break;
	default: cout << "It's not weekday number" << endl;
	}
	system("pause");
	return 0;
}
