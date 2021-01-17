#include "iostream"
using namespace std;

int ExchangeVal(int *p_a, int *p_b)
{
	if (*p_a < *p_b) return *p_a;
	else return *p_b;
}

void main()
{
	int a = 10, b = 20;
	int *p_a = &a;
	int *p_b = &b;
	int min = ExchangeVal(p_a, p_b);
	cout << "Min= " << min << endl;
	

	system("pause");
}