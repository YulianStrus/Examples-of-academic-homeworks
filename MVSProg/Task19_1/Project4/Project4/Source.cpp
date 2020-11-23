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

	int tmp;
	
	for (int i = 1; i < size - 10; ++i)
	{
		tmp = arr[i];
		for (int j = i - 1; j >= 0 & arr[j] > tmp; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = tmp;
		}
	}

	for (int i = size - 9; i < size; ++i)
	{
		tmp = arr[i];
		for (int j = i - 1; j >= 0 & arr[j] < tmp; j--)
		{
			arr[j + 1] = arr[j];
			arr[j] = tmp;
		}
	}

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl << endl;

	system("pause");
}
