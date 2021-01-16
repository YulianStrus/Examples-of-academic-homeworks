#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()

{
	const int size = 10;
	int arr[size];
	int Sum = 0;
	int x = 15, y = -15, srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (x - y) + y;
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	for (int i = 1; i < size; i += 2)
	{
		int t = arr[i - 1];
		arr[i - 1] = arr[i];
		arr[i] = t;
	}

	for (int i = 0; i < size; i++) cout << arr[i] << " ";
	cout << endl;

	system("pause");
}