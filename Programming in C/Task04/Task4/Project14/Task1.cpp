#include "iostream"
using namespace std;
void main()
{
	double a, p, s, r;
	cout << "Enter the price of the item ";
	cin >> a;
	cout << "Enter the amount of discounts ";
	cin >> p;
	s = a / 100 * p;
	r = a - s;
	cout << "Discounted price = " << r << "\nDiscount amount = " << s << endl;
	system("pause");
}
