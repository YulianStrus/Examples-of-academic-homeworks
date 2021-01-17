#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int size = 20;
	int arr[size];
	int Sum = 0;
	int x = 15, y = -15, srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (x - y) + y;
		cout << arr[i] << " ";
	}
	cout << endl << endl;

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


	for (int i = 1; i < size - 1; i+=2)
	{
		min = i;
			for (int j = i + 2; j < size; j+=2)
			{
				if (arr[j] > arr[min]) min = j;
			}
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;

	}


	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	system("pause");
}