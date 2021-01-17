#include "iostream"
using namespace std;
int main()
{
	double a, Dob = 1;
	cout << "Enter number " << endl;
	cin >> a;
	while (a <= 20)
	{
		Dob *= a;
		a++;
	}
	cout << "Product number = " << Dob << endl;
	system("pause");
}
