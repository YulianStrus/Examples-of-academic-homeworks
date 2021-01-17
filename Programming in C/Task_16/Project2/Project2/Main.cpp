#include "Header.h"
int main()
{
	const int size = 10;
	int arr[size];
	RandArr(arr, size);
	cout << "it is array: \t";
	ShowArr(arr, size);
	cout << endl;
	cout << "Sum number of array = " << SumArr(arr, size) << endl;
	cout << "Product number of array = " << ProdArr(arr, size) << endl;
	cout << "Max number of array = " << MaxArr(arr, size) << endl;

	system("pause");
}