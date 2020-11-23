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

void TranspArray(int arr[], int size)
{
	for (int i = size - 1; i >= 0; --i)
		cout << arr[i] << " ";
}


void main()
{
	const int size = 10;
	int arr[size];
	RandomArray(arr, size);
	cout << "it is array: \t\t";
	ShowArray(arr, size);
	cout << "it is new array: \t";
	TranspArray(arr, size);
	cout << endl;

	system("pause");
}
