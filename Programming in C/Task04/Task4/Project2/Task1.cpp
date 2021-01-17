#include "iostream"
using namespace std;
void main()
{
	float a, b, c, S, V, k;
	cout << "Enter length ";
	cin >> a;
	cout << "Enter width ";
	cin >> b;
	cout << "Enter height ";
	cin >> c;
	S = a * b;
	V = S * c;
	k = S / 0.05;
	cout  << "Volume = " << V << "\nSquare = " << S << "\nNumber of tiles = " << k << endl;
	system("pause");
}
