#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

template <typename T>

T MaxNum(T arr[], int size)
{
	int x = 20, y = -10, srand(time(NULL));
	for (int i = 0; i < size; i++) { arr[i] = rand() % (x - y) + y; cout << arr[i] << " "; }

	cout << endl;
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if (arr[i]>max) max = arr[i];
	
	return  max;
}



int main()
{
	const int size = 20;
	int arr[size];
	int Max = MaxNum(arr, size);
	cout << "Max number = " << Max << endl;

	system("pause");
}