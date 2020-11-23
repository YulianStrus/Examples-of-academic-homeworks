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

bool check_num(int n)

{
	int k = 0;
	for (int i = 2; i <= n; i++)

	{

		if ((n % i) == 0)
			k++;

	}
	if (k > 1)
		return false;
	else
		return true;
}

int SimpNum(int arr[], int size)
{
	int k = 0;
	for (int i = 0; i < size; i++)

	{

		if (check_num(arr[i]) == true)
			k++;
	}
	return k;
}



void main()
{
	const int size = 10;
	int arr[size];
	RandomArray(arr, size);
	cout << "it is array: \t";
	ShowArray(arr, size);
	cout << "Number of prime numbers = " << SimpNum(arr, size) << endl;

	system("pause");
}
