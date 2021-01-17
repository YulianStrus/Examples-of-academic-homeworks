#include "Header.h"
void RandArr(char arr[], int size)
{
	char x = 'a', y = 'z';
	int i = 0;
	for (int i = 0; i < size; ++i) arr[i] = rand() % (x - y) + y;;
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << endl;
}

void ReArr(int arr[], int size)
{
	for (int i = size - 1; i >= 0; i--)
		cout << arr[i] << " ";
}

void ReArr(double arr[], int size)
{
	for (int i = size - 1; i >= 0; i--)
		cout << arr[i] << " ";
}

void ReArr(char arr[], int size)
{
	for (int i = size - 1; i >= 0; i--)
		cout << arr[i] << " ";
}