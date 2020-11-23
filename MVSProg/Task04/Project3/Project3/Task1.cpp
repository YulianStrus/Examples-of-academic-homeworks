#include "iostream"
using namespace std;
void main()
{
	float k, x, l, v, m, S, G;
	cout << "Enter number ";
	cin >> k;
	x = (k * 0.5 * 60) + (k * 0.3 * 40) + (k * 0.2 * 20);
	cout << "Enter length of the route ";
	cin >> l;
	cout << "Enter the amount of fuel consumption ";
	cin >> v;
	cout << "Enter the price of fuel ";
	cin >> m;
	S = (l * k) * (v*0.01) * m;
	G = x - S;
	cout << "Calculate profit based on gasoline costs " << G << endl;
	system("pause");
}
