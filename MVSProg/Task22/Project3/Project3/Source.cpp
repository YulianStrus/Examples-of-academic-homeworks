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
void MinMax(int arr[], int size)
{
	int max = arr[0], k;
	for (int i = 1; i < size; ++i) if (arr[i] > max) { max = arr[i]; k = i; }
	cout << "Max " << k << " = " << max << endl;

	int min = arr[0], n;
	for (int i = 1; i < size; ++i) if (arr[i] < min) { min = arr[i]; n = i; }
	cout << "Min " << n << " = " << min << endl;
}


void main()
{
	const int size = 10;
	int arr[size];
	RandomArray(arr, size);
	cout << "it is array: ";
	ShowArray(arr, size);
	MinMax(arr, size);

	system("pause");
}
