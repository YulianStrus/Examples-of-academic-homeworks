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
	int tmp1;
	bool change1 = true;
	while (change1)
	{
		change1 = false;
		for (int i = 0; i < size - 1; ++i)
		{
			if (arr[i]<arr[i + 1])
			{
				tmp1 = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp1;
				change1 = true;
			}
		}

	/*	change1 = false;
		for (int i = size - 1; i > 1; ++i)
		{
			if (arr[i + 1] < arr[i])
			{
				tmp1 = arr[i];
				arr[i + 1] = arr[i];
				arr[i] = tmp1;
				change1 = true;
			}
		}*/
	}
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	system("pause");
}