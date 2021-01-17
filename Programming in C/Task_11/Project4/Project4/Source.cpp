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
	cout << endl;

	int tmp;
	bool change = true;
	while (change)
	{
		change = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				change = true;
			}
		}
	}
	change = true;
	while (change)
	{
		change = false;
		for (int i = 1; i < size - 1; i+=2)
		{
			if (arr[i] < arr[i + 2])
			{
				tmp = arr[i];
				arr[i] = arr[i + 2];
				arr[i + 2] = tmp;
				change = true;
			}
		}
	}

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl << endl;
	system("pause");
}