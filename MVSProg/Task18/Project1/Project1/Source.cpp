#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int size = 10;
	int arr[size];
	int x = 15, y = -15, srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (x - y) + y;
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	int temp;
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 0; i < size-1; ++i)
		{
			if (arr[i]>arr[i+1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				change = true;
			}
		}

		change = false;
		for (int i = size - 1; i > 1; ++i)
		{
			if (arr[i + 1] > arr[i])
			{
				temp = arr[i];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				change = true;
			}
		}
	}

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	system("pause");
}