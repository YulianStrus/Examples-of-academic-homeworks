#include "iostream"
#include "math.h"
using namespace std;
void main()
{
	double a, y, x;
	cout << "Enter number ";
	cin >> a;
	y = round(a*100)/100;
	cout << "=" << y << endl;
	system("pause");
}
