#include "Header.h"
#include "Header.h"
void main()
{
	const int size = 10;
	int arr[size];
	RandArr(arr, size);
	cout << endl;
	cout << "k0 = " << NullArr(arr, size) << endl;

	double a;
	cout << "Enter number: " << endl;
	cin >> a;
	cout << "k > " << a << " = " << MaxArr(arr, size, a) << endl;

	double b;
	cout << "Enter number: " << endl;
	cin >> b;
	cout << "k < " << b << " = " << MinArr(arr, size, b) << endl;


	system("pause");
}