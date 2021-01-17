#include "Header.h"

void RandArr(int arr[], int arr1[], int arrs[], int size)
{
	int i=0;
	for (int i = 0; i < size; ++i) arr[i] = rand() % 20;
	for (int i = 0; i < size; ++i) cout << arr[i] << "\t ";
	cout << endl;
	for (int i = 0; i < size; ++i) arr1[i] = rand() % 20;
	for (int i = 0; i < size; ++i) cout << arr1[i] << "\t ";
	cout << endl;
	for (i = 0; i < size; i++)	arrs[i] = arr[i] + arr1[i];
	for (int i = 0; i < size; ++i) cout << arrs[i] << "\t ";

}