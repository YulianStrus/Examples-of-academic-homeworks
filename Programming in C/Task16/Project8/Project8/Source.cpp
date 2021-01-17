#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()
{
	const int size = 10;
	int arr[size];
	int x = 15, y = -15, srand(time(NULL));
	for (int i = 0; i < size; i++) arr[i] = rand() % (x - y) + y;
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl << endl;
		
	int min = 0, max = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < arr[min])
			min = i;

		if (arr[i] > arr[max])
			max = i;
	}

	int tmp = arr[max];
	arr[max] = arr[min];
	arr[min] = tmp;


	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl << endl;
	system("pause");
}