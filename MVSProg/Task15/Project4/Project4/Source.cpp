#include <iostream>
#include <math.h>
using namespace std;
void main()
{
	int o, i, k=0;
	double n, Sa, Su = 0;
	cout << "Vvedite chyslo " << endl;;
	cin >> n;
	o = n;
	for (i = 0; o >= 1; i++)
	{
		o /= 10; 
		n = n - (o * 10);
		Su += n;
		n = o;
		k += 1;
	}
	Sa = Su / k;
	cout << "Number of digits = " << k << endl;
	cout << "Sum of digits = " << Su << endl;
	cout << "Arithmetic mean digits = " << Sa << endl;
	system("pause");
}