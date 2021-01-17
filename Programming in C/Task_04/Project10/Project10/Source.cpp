#include "iostream"
using namespace std;
int main()
{
	int k, Dob = 0, i = 1;
	cout << "Enter number k " << endl;
	cin >> k;
	while (i <= 10)
	{
		Dob = k*i;
		cout << "k*"<< i <<" = " << Dob << endl;
		i += 1;
	}
	
	system("pause");
}
