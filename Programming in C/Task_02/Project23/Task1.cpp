#include "iostream"
using namespace std;
void main()
{
	float a, b, c;
	cout << "Enter the desired salary amount ";
	cin >> b;
	cout << "Enter the bid per hour ";
	cin >> a;
	c=b/a;
	cout << "It is necessary to work " << c << " hours" << endl;
	system("pause");
}
