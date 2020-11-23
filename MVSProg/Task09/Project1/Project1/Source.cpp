#include "iostream"
using namespace std;
int main()
{
	int x, b = 4; double y;
	cout << "Enter x ";
	cin >> x;
	(x < -3) ? y = x - b : ((x >= -3)&(x < 3) ? y = x + b : ((x >= 3)&(x < 24) ?y =  (x * x - b) / 2 : ((x >= 24) & (x < 75) ? y = (x*x + b) / 3 : y = (x*x - b) / 6)));
	cout << "y= " << y << endl;
	system	("pause");
	return 0;
}