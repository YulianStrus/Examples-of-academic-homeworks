#include "iostream"
using namespace std;
void main()
{
	int a, b, c;
	cout << "Enter three number: " << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	int *p_a = &a;
	int *p_b = &b;
	int *p_c = &c;
	int Prod = *p_a* *p_b* *p_c;
	cout << "Production = " << Prod << endl;
	int Am = (*p_a* *p_b* *p_c) / 3;
	cout << "Arithmetic mean = " << Am << endl;
	if ((*p_a < *p_b)&(*p_a < *p_c)) cout << "Min number = " << *p_a << endl;
	if ((*p_b < *p_a)&(*p_b < *p_c)) cout << "Min number = " << *p_b << endl;
	if ((*p_c < *p_a)&(*p_c < *p_b)) cout << "Min number = " << *p_c << endl;

	system("pause");
}