#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

template <typename T>

T ArithmMean(T arr[], int size)
{
	int x = 20, y = -5, srand(time(NULL));
	for (int i = 0; i < size; i++) { arr[i] = rand() % (x - y) + y; cout << arr[i] << " "; }

	cout << endl;
	double AM = 0, k=0;
	for (int i = 0; i < size; i++)
	{
		AM += arr[i]; k++;
	}
	return  AM / k;
}



int main()
{
	const int size = 20;
	double arr[size];
	double AM = ArithmMean(arr, size);
	cout << "Arithmetic mean = " << AM << endl;

	system("pause");
}