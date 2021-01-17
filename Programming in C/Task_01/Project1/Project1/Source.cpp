#include "iostream"
using namespace std;
void main()
{
	int a;
	cout << "Please input digit ";
	cin >> a;
	if (a % 2 == 0) cout << "This number is a pair" << endl; else cout << "This number is odd" << endl;
	system("pause");
}