#include "Header.h"
void RandArr(int arr[], int size)
{
	int x = 5, y = -10;
	int i = 0;
	for (int i = 0; i < size; ++i) arr[i] = rand() % (x - y) + y;;
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << endl;
}

int NullArr(int arr[], int size)
{
	int k = 0;
	for (int i = 0; i < size; ++i) 
		if (arr[i]==0) k++;
	return k;
	
}

int MaxArr(int arr[], int size, int x)
{
	int k = 0;
	for (int i = 0; i < size; ++i)
		if (arr[i] > x) k++;
	return k;
}
double MaxArr(double arr[], double size, double x)
{
	double k = 0;
	for (int i = 0; i < size; ++i)
		if (arr[i] > x) k++;
	return k;
}

int MinArr(int arr[], int size, int x)
{
	int k = 0;
	for (int i = 0; i < size; ++i)
		if (arr[i] < x) k++;
	return k;
}
double MinArr(double arr[], double size, double x)
{
	double k = 0;
	for (int i = 0; i < size; ++i)
		if (arr[i] < x) k++;
	return k;
}