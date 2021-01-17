#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;
void main()
{
	const int size = 30;
	int arr[size];
	arr[0] = 1;
	cout << arr[0] << endl;
	arr[1] = 2;
	cout << arr[1] << endl;
	for (int i = 2; i < size; i++)
	{
		arr[i] = arr[i-1] * 2;
		cout << arr[i] << endl;
	}
	for (int i = size; i >= 0; i--)

		cout << arr[i] << endl;

	system("pause");
}