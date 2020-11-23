#include "iostream"
using namespace std;
void main()
{
	int a, i = 0, k = 1;
	
	do
	{
		a = k * 2;
		k = a;
		i = i + 3;
		cout << "After " << i << " hours there will be " << a << " cells" << endl;
	} while (i<24);

	

	system("pause");
}