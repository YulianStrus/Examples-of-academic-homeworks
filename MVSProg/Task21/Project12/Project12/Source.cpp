#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

void SimpNumb(int a, int b, int c)
{
	do {
		if (a%b == 0) ++c; ++b;
	} while (b <= a);
	if (c == 2) cout << "Yes, this number is simple" << endl;
	else cout << "No, this number is not simple" << endl;
}
void main()
{

	int a;
	cout << "Enter number: " << endl;
	cin >> a;
	SimpNumb(a, 1, 0);



	system("pause");
}
