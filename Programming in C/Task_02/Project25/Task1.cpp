#include "iostream"
using namespace std;
void main()
{
	double a, b, h, m;
	cout << "Enter the number of contacts ";
	cin >> a;
	cout << "Enter the average number of minutes ";
	cin >> b;
	h = (480 - (a*b) - 30);
	int n = h / 60;
	m = h - (n*60);
	cout << "The person is directly engaged in work " << n << " hours " << m << " minutes " << endl;
	system("pause");
}
