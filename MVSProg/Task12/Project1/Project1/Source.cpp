#include "iostream"
using namespace std;
void main()
{
	int a=0, b;
	cout << "Enter start " << endl;
	cin >> b;
	do 
	{
		(cout << a << " ");
		a += 1;
	} 
	while (a <= b);
	system("pause");
}
