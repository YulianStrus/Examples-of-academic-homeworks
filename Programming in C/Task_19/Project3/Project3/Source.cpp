#include "iostream"
using namespace std;

int ExchangeVal(int *p_a, int *p_b)
{
	int tmp = *p_a;
	*p_a = *p_b;
	*p_b = tmp;
	return *p_a;
	return *p_b;
}

void main()
{
	int a = 10, b = 20;
	int *p_a = &a;
	int *p_b = &b;
	ExchangeVal(p_a, p_b);
	cout << "a= " << a << endl;
	cout << "b= " << b << endl;

	system("pause");
}