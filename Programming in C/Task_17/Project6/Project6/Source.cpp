#include "iostream"
using namespace std;

void RandArr(int arr[], int size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 20;
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
}

int MinArr(int arr[], int A, int size)
{
	int Sum=0, Min=0;
	for (int i = A; i < size; i++) {
		Sum += arr[i];
		Min = A;
	}
	if (A==0)	return Sum;
	if (Sum < MinArr(arr, A - 1, size - 1)) {
		Min = A;
		return Sum;
	}
}


void main()
{
	const int size = 100;
	int arr[size];
	int A = size-10;
	RandArr(arr,size);
	cout << endl << endl;
	cout << MinArr(arr, A, size) << endl;

	system("pause");
}