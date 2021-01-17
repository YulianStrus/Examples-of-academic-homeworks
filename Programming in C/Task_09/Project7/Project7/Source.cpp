#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()
{
	const int size = 15;
	int arr[size];
	int x = 10, y = -10, srand(time(NULL));
	for (int i = 0; i < size; i++) arr[i] = rand() % (x - y) + y;
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
			arr[i] = arr[i] * (-1);
		cout << arr[i] << " ";
	}

	cout << endl;

	system("pause");
}