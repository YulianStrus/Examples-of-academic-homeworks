#include "iostream"
#include "stdlib.h"
#include "time.h"
using namespace std;

template <typename T>

void SymbPunct(T arr[], int size)
{
	int x = 20, y = -5, srand(time(NULL));
	for (int i = 0; i < size; i++) { arr[i] = rand() % (x - y) + y; cout << arr[i] << " "; }

	cout << endl;
	cout << "i[0]= ";
	for (int i = 0; i < size; i++)
		if (arr[i] == 0) cout << i << " ";
	cout << endl;
}



int main()
{
	const int size = 20;
	int arr[size];
	SymbPunct(arr, size);


	system("pause");
}