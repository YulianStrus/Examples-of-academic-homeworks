#include <iostream>
#include <math.h>
using namespace std;
void main()
{
	int o, i;
	float n;
	cout << "Vvedite chyslo " << endl;;
	cin >> n;
	o = n;
	for (i = 0; o >= 1; i++)
	{
		o /= 10;
		n = n - (o * 10);
		cout << n << " ";
		n = o;
	}
	system("pause");
}