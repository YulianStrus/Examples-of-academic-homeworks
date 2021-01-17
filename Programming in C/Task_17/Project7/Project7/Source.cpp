#include <iostream>
using namespace std;

void RandArr(int arr[], int size)
{
	for (int i = 0; i < size; i++) arr[i] = rand() % 50;

	int tmp, min;
	for (int i = 0; i < size - 1; ++i)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min]) min = j;
		}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
	}

	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
}

int BinSearch(int arr[], int size, int k)
{
	
	int B = 0, E = size - 1, mid;

	while (B <= E)
	{
		mid = (B + E) / 2;

		if (k == arr[mid])
			return mid;
		else if(k > arr[mid])
			B = mid + 1;
		else
			E = mid - 1;
	}
	return  -1;
}

int main()
{
	const int size = 10;
	int arr[size];
	int k;

	RandArr(arr, size);
	cout << endl;

	cout << "Enter number: ";
	cin >> k;

	int n = BinSearch(arr, size, k);
	cout << "Position number " << k << " = " << n << endl;


	system("pause");
}

