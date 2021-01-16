#include "iostream"
using namespace std;
void main()
{
	double i=0, k;
	cout << "Enter a step: " << endl;
	cin >> k;
	for (i = 0; i<=10; i += k)
	 cout << i << " ";

	system("pause");
}
