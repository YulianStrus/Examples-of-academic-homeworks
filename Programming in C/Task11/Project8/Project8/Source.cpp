#include "iostream"
using namespace std;
int main()
{
	int a=1, Sa = 0;
	while (a <= 1000)
	{
		Sa += a;
		a++;
	}
	Sa /= 1000;
	cout << "Arithmetic mean = " << Sa << endl;
	system("pause");
}
