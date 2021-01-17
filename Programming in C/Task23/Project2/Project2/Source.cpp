#include "Header.h"
#include "time.h"

void RandArr(int arr[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i) arr[i] = rand() % 20;
}
void ShowArr (int arr[], int size)
{
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << endl;
}
int SumArr(int arr[], int size)
{
	int k = 0;
	for (int i = 0; i < size; ++i) k+=arr[i];
	return k;
}
double ProdArr(int arr[], int size)
{
	double k = 1;
	for (int i = 0; i < size; ++i) k *= arr[i];
	return k;
}
int MaxArr(int arr[], int size)
{
	int max = arr[0]; 
	{
		for (int i = 1; i < size; ++i)
			if (arr[i] > max) max = arr[i]; 
	}
	return max;
}