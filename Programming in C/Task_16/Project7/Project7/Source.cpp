#include "Header.h"
void RandArr(int arr[], int size)
{
	int x = 15, y = -5;
	int i = 0;
	for (int i = 0; i < size; ++i) arr[i] = rand() % (x - y) + y;;
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << endl;
}

int MinElem(int arr[], int size)
{
	int min = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] < min) min = arr[i];
	return min;
}

int MinIElem(int arr[], int size)
{
	int min = arr[0];
	int k = 0;
	for (int i = 1; i < size; i++)
		if (arr[i] < min) { min = arr[i];  k = i;}
	return k;
}

int MaxElem(int arr[], int size)
{
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i] > max) max = arr[i];
	return max;
}

int MaxIElem(int arr[], int size)
{
	int max = arr[0];
	int k = 0;
	for (int i = 1; i < size; i++)
		if (arr[i] > max) { max = arr[i];  k = i; }
	return k;
}
