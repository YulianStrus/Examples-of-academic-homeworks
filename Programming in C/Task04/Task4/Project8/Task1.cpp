#include "iostream"
using namespace std;
void main()
{
	float a, b, c, d, e, S;
	cout << "Enter the five student ratings ";
	cin >> a >> b >> c >> d >> e;
	S = (a + b + c + d + e) / 5;
	cout << "Average arithmetic numbers = " << S << endl;
	system("pause");
}
