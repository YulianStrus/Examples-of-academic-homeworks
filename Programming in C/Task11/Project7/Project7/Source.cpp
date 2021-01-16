#include "iostream"
using namespace std;
int main()
{
	int x, y, Dob=1, i=1;
	cout << "Enter number x " << endl;
	cin >> x;
	cout << "Enter number y " << endl;
	cin >> y;
	while (i <= y)
	{
		Dob *= x;
		i+=1;
	}
	cout << "x^y = " << Dob << endl;
	system("pause");
}
