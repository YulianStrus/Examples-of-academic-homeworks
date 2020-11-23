#include "iostream"
#include "time.h"
using namespace std;
void RandomArray(int arr[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i) arr[i] = rand() % 20;
}
void ShowArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << endl;
}

void ElemMatrix (int arr[], int size)
{
	int k = 0, n = 0, m = 0;
	for (int i = 0; i < size; ++i)
			if (arr[i] == 0) k++;
			else if (arr[i] < 0) n++;
			else if (arr[i] > 0) m++;
	cout << "The number of zero elements in the array = " << k << endl;
	cout << "Number of negative array elements = " << n << endl;
	cout << "Number of positive array elements = " << m << endl;
}

void main()
{
	const int size = 10;
	int arr[size];
	RandomArray(arr, size);
	cout << "it is array: ";
	ShowArray(arr, size);
	ElemMatrix(arr, size);

	system ("pause");
}