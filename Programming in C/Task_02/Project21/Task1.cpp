#include "iostream"
using namespace std;
void main()
{
	float a;
	cout << "Enter the volume in gigabytes ";
	cin >> a;
	a *= 8589934592;
	cout << "Volume in bites = " << a << endl;
	system("pause");
}
