#include "iostream"
#include "time.h"
using namespace std;

void RandomArray(int arr[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; ++i) arr[i] = rand() % 20;
}
void ShowArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i) cout << arr[i] << " ";
	cout << endl;
}

double SerArMas (int arr[], int size)
{
	double SM=0; 
	for (int i = 0; i < size; ++i)
	{
			SM = SM + arr[i];
	}
	return (SM / size);
}

void main()
{
	const int size = 10;
	int arr[size];
	RandomArray(arr, size);
	cout << "it is array: ";
	ShowArray(arr, size);
	double SR = SerArMas(arr, size);
	cout << "Arithmetic mean array = " << SR << endl;

	system("pause");
}