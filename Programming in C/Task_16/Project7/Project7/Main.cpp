#include "Header.h"

void main()
{
	const int size = 10;
	int arr[size];
	RandArr(arr, size);
	cout << endl;
	cout << "Min element "<< MinIElem(arr, size) << " = " << MinElem(arr, size) << endl;
	cout << "Max element " << MaxIElem(arr, size) << " = " << MaxElem(arr, size) << endl;
	

	system("pause");
}