#include "iostream"
using namespace std;
int main()
{
	int a, Sum=0;
	cout << "Enter number " << endl;
	cin >> a;
	while (a <= 500)
	{
		Sum +=a;
		a++;
	}
	cout << "Sum = " << Sum << endl;
	system("pause");
}
