#include <iostream> 
using namespace std;

void main()
{
	double x, y;
	cout << "Enter x ";
	cin >> x;
	if (x > 0) 
	{
		y = sqrt((x*x*x) - (sqrt(x - 1)));
		cout << "y = " << y << endl;
	}
	else cout << "Error" << endl;
	system("pause");
}
