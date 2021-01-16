
#include "iostream"
#include "time.h"
#include "stdlib.h"
using namespace std;

void CreateMas(int *mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		mas[i] = rand() % 20; cout << mas[i] << " ";
	}
	cout << endl;
}
void CreateArr(int *arr, int size_a)
{
	for (int i = 0; i < size_a; i++)
	{
		arr[i] = rand() % 50; cout << arr[i] << " ";
	}
	cout << endl;
}

void TranspMas(int *mas, int size, int *arr, int size_a)
{
	int t = size;
	int *tmp = new int[size];
	for (int i = 0; i < size; i++)
		tmp[i] = mas[i];
	delete[] mas;
	size = size_a;
	mas = new int[size];
	for (int i = 0; i < size; i++)
		mas[i] = arr[i];
	delete[] arr;
	size_a = t;
	arr = new int[size_a];
	for (int i = 0; i < size_a; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	for (int i = 0; i < size; i++) cout << mas[i] << " ";
	cout << endl;
	for (int i = 0; i < size_a; i++) cout << arr[i] << " ";
}


void main()
{
	const int size = 20;
	const int size_a = 15;
	int *mas = new int[size];
	int *arr = new int[size_a];
	CreateMas(mas, size);
	CreateArr(arr, size_a);
	cout << "New masiv:" << endl;
	TranspMas(mas, size, arr, size_a);	

	system("pause");
}